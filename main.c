#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <signal.h>
#include <syscall.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <unistd.h>
#include <errno.h>
#include <libdwarf-0/dwarf.h>
#include <libdwarf-0/libdwarf.h>
#include "debuglib.h"
#include <string.h>

/* Print a message to stdout, prefixed by the process ID
//  */
// void procmsg(const char *format, ...)
// {
//     va_list ap;
//     fprintf(stdout, "[%d] ", getpid());
//     va_start(ap, format);
//     vfprintf(stdout, format, ap);
//     va_end(ap);
// }

// void run_target(const char *programname)
// {
//     procmsg("target started. will run '%s'\n", programname);

//     /* Allow tracing of this process */
//     if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
//     {
//         perror("ptrace");
//         return;
//     }

//     /* Replace this process's image with the given program */
//     execl(programname, programname, 0);
// }

// void run_debugger(pid_t child_pid)
// {
//     int wait_status;
//     unsigned icounter = 0;
//     procmsg("debugger started\n");

//     /* Wait for child to stop on its first instruction */
//     wait(&wait_status);

//     while (WIFSTOPPED(wait_status))
//     {
//         icounter++;
//         struct user_regs_struct regs;
//         ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
//         unsigned instr = ptrace(PTRACE_PEEKTEXT, child_pid, regs.rip, 0);

//         procmsg("icounter = %u.  EIP = 0x%08x.  instr = 0x%08x\n",
//                 icounter, regs.rip, instr);

//         /* Make the child execute another instruction */
//         if (ptrace(PTRACE_SINGLESTEP, child_pid, 0, 0) < 0)
//         {
//             perror("ptrace");
//             return;
//         }

//         /* Wait for child to stop on its next instruction */
//         wait(&wait_status);
//     }

//     procmsg("the child executed %u instructions\n", icounter);
// }

int main(int argc, char **argv)
{
    pid_t child_pid;

    if (argc < 2)
    {
        fprintf(stderr, "Expected a program name as argument\n");
        return -1;
    }

    child_pid = fork();
    if (child_pid == 0)
        run_target(argv[1]);
    else if (child_pid > 0)
    {
        static char true_pathbuf[FILENAME_MAX];
        unsigned tpathlen = FILENAME_MAX;
        Dwarf_Handler errhand = 0;
        Dwarf_Ptr errarg = 0;
        Dwarf_Error err = 0;
        Dwarf_Debug dbg = 0;
        int res = 0;
        res = dwarf_init_path(argv[1], true_pathbuf,
                              tpathlen, DW_GROUPNUMBER_ANY, errhand,
                              errarg, &dbg, &err);
        if (res == DW_DLV_ERROR)
        {
            /* Necessary call even though dbg is null!
            This avoids a memory leak. */
            dwarf_dealloc_error(dbg, err);
            return -2;
        }
        if (res == DW_DLV_NO_ENTRY)
        {
            /* Nothing we can do */
            return -2;
        }
        printf("The file we actually opened is %s\n",
               true_pathbuf);

        debug_breakpoint *bp;
        Dwarf_Die die;
        res = dwarf_siblingof_b(dbg, 0, 1, &die, &err);
        // if (res == DW_DLV_OK)
        // {
            while (1)
            {
                char *name;
                Dwarf_Attribute attr;
                res = dwarf_diename(die, &name, &err);
                if (strcmp(name, "do_stuff") == 0)
                {
                    // Found the function "do_stuff"
                    Dwarf_Addr low_pc;
                    res = dwarf_attr(die, DW_AT_low_pc, &attr, &err);
                    if (res == DW_DLV_OK)
                    {
                        dwarf_formaddr(attr, &low_pc, &err);
                        // Set a breakpoint at the entry of the function
                        debug_breakpoint *bp = create_breakpoint(child_pid, (void *)low_pc);
                        procmsg("breakpoint created\n");
                    }
                    break;
                }

                Dwarf_Die sibling;
                res = dwarf_siblingof_b(dbg, die,1, &sibling, &err);
                if (res == DW_DLV_OK)
                {
                    die = sibling;
                }
                else
                {
                    break;
                }
            }
        //}

        ptrace(PTRACE_CONT, child_pid, 0, 0);
        wait(0);

        /* Loop as long as the child didn't exit */
        while (1)
        {
            /* The child is stopped at a breakpoint here. Resume its
            ** execution until it either exits or hits the
            ** breakpoint again.
            */
            struct user_regs_struct regs;
            ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
            procmsg("child stopped at breakpoint. RIP = %p\n", regs.rip);
            procmsg("RAX = %p\n", regs.rax);
            procmsg("resuming\n");
            int rc = resume_from_breakpoint(child_pid, bp);

            if (rc == 0)
            {
                procmsg("child exited\n");
                break;
            }
            else if (rc == 1)
            {
                continue;
            }
            else
            {
                procmsg("unexpected: %d\n", rc);
                break;
            }
        }

        // Dwarf_Off offset;
        // Dwarf_Func *func = 0;

        //int res = dwarf_func_name_offsets("do_stuff", &offset, &error);
        // if (res == DW_DLV_OK)
        // {
        //     Dwarf_Die die;
        //     res = dwarf_offdie_b(dbg, offset, &die, &error);
        //     if (res == DW_DLV_OK)
        //     {
        //         Dwarf_Addr low_pc;
        //         Dwarf_Attribute attr;
        //         res = dwarf_attr(die, DW_AT_low_pc, &attr, &error);
        //         if (res == DW_DLV_OK)
        //         {
        //             dwarf_formaddr(attr, &low_pc, &error);
        //             // Set a breakpoint at the entry of the function
        //             debug_breakpoint *bp = create_breakpoint(child_pid, (void *)low_pc);
        //             procmsg("breakpoint created\n");
        //             ptrace(PTRACE_CONT, child_pid, 0, 0);
        //             wait(0);

        //             /* Loop as long as the child didn't exit */
        //             while (1)
        //             {
        //                 /* The child is stopped at a breakpoint here. Resume its
        //                 ** execution until it either exits or hits the
        //                 ** breakpoint again.
        //                 */
        //                 struct user_regs_struct regs;
        //                 ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
        //                 procmsg("child stopped at breakpoint. RIP = %p\n", regs.rip);
        //                 procmsg("child stopped at breakpoint. RAX = %p\n", regs.rax);
        //                 procmsg("resuming\n");
        //                 int rc = resume_from_breakpoint(child_pid, bp);

        //                 if (rc == 0)
        //                 {
        //                     procmsg("child exited\n");
        //                     break;
        //                 }
        //                 else if (rc == 1)
        //                 {
        //                     continue;
        //                 }
        //                 else
        //                 {
        //                     procmsg("unexpected: %d\n", rc);
        //                     break;
        //                 }
        //             }
        //         }
    //  }
}
else
{
    perror("fork");
    return -1;
}

return 0;
}
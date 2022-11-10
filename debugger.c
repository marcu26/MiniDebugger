#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/personality.h>
#include <unistd.h>
#include "debugger.h"


void set_breakpoint(pid_t pid, u_int64_t address)
{
    ptrace(PTRACE_POKEDATA,pid,address,0xcc);
}

void next_step(pid_t pid, int wait_status,int *icounter)
{
        int icounter_copy=*icounter;
        icounter_copy++;
        struct user_regs_struct regs;
       // 562aa03cf000
        ptrace(PTRACE_GETREGS, pid, 0, &regs);
        unsigned instr = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, 0);

        printf("icounter = %u.  EIP = 0x%08x.  instr = 0x%08x\n", icounter_copy, regs.rip, instr);


        if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) < 0) 
        {
            perror("ptrace");
            return;
        }

        *icounter=icounter_copy;

        wait(&wait_status);
}

void next_sys_call(pid_t pid, int wait_status,int *icounter)
{
        int icounter_copy=*icounter;
        icounter_copy++;
        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, 0, &regs);
        unsigned instr = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, 0);

        printf("icounter = %u.  EIP = 0x%08x.  instr = 0x%08x\n", icounter_copy, regs.rip, instr);


        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) < 0) 
        {
            perror("ptrace");
            return;
        }

        *icounter=icounter_copy;

        wait(&wait_status);
}


void run_debugger(pid_t child_pid)
{
    int wait_status;
    unsigned icounter = 0;
    printf("debugger started\n");



    ptrace(PTRACE_POKEDATA,child_pid,0x562aa03cf000+0x0000000000001149,0xcc);
    ptrace(PTRACE_CONT,child_pid,0,0);

    wait(&wait_status);

    while (WIFSTOPPED(wait_status)) 
    {
        int a = get_command();

        if (a==1)
        {
            next_step(child_pid,wait_status,&icounter);
        }
        else if(a==2)
        {
            next_step(child_pid,wait_status,&icounter);
        }

    }

    printf("the child executed %u instructions\n", icounter);
}


void run_target(const char* programname)
{

    printf("target started. will run '%s'\n", programname);

   
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) 
    {
        perror("ptrace");
        return;
    }

    personality(ADDR_NO_RANDOMIZE);
    execl(programname, programname, 0);
}
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <unistd.h>
#include <errno.h>

#include <dlfcn.h>

#include <elf.h>
#include "debuglib.h"
#include <libdwarf-0/dwarf.h>
#include <libdwarf-0/libdwarf.h>

void *get_symbol_addr(const char *executable_name, const char *symbol_name)
{
    void *handle = dlopen(executable_name, RTLD_NOW);
    if (!handle)
    {
        fprintf(stderr, "Error: dlopen() failed: %s\n", dlerror());
        return 0;
    }

    void *symbol_addr = dlsym(handle, symbol_name);
    if (!symbol_addr)
    {
        fprintf(stderr, "Error: dlsym() failed: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    dlclose(handle);
    return symbol_addr;
}

int print_local_variables(pid_t child_pid,
                          const char *executable_name,
                          const char *function_name)
{
    /* First get the address of the function in the child process */
    void *function_addr = dlsym((void *)0, function_name);
    if (!function_addr)
    {
        return -1;
    }

    /* Now get the list of symbols in the function */
    Dl_info info;
    int res = dladdr(function_addr, &info);
    if (res == 0)
    {
        fprintf(stderr, "Error: dladdr() failed: %s\n", dlerror());
        return -1;
    }

    /* For each symbol, read its value from the child process and print it */
    Elf64_Sym *symbol_table = (Elf64_Sym *)info.dli_saddr;
    const char *string_table = (const char *)info.dli_sname;
    Elf64_Sym *symbol;
    const char *name;

    /* Get the number of symbols in the symbol table */
    int num_symbols = 0;
    while (symbol_table[num_symbols].st_name != 0)
    {
        num_symbols++;
    }

    for (int i = 0; i < num_symbols; i++)
    {
        symbol = &symbol_table[i];
        name = &string_table[symbol->st_name];
        if (ELF64_ST_TYPE(symbol->st_info) == STT_OBJECT)
        {
            printf("%s = %ld\n", name, ptrace(PTRACE_PEEKDATA, child_pid, (void *)symbol->st_value, 0));
        }
    }

    return 0;
}
int main(int argc, char *argv[])
{

    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        // This is the child process. Run the target program.
        run_target(argv[1]); // argv[1] will be the executable name
    }
    else
    {
        // This is the parent process. Wait for the child to stop at the entry
        // point.
        int wait_status;
        waitpid(child_pid, &wait_status, 0);

        // Find the address of the target function
        void *target_function_addr = get_symbol_addr(argv[1], argv[2]); // argv[2] will be the desired function name to put the breakpoint on
        if (target_function_addr == 0)
        {
            fprintf(stderr, "Error: could not find address of function %s in %s\n",
                    argv[2], argv[1]);
            return 1;
        }

        // Set a breakpoint at the start of the target function
        debug_breakpoint *bp = create_breakpoint(child_pid, target_function_addr);

        // Continue execution until we reach the breakpoint
        ptrace(PTRACE_CONT, child_pid, 0, 0);
        waitpid(child_pid, &wait_status, 0);
        disable_breakpoint(child_pid, bp);

        // Print the values of the local variables in the target function
        print_local_variables(child_pid, argv[1], argv[2]);

        // Resume execution and wait for the child to exit
        ptrace(PTRACE_CONT, child_pid, 0, 0);
        waitpid(child_pid, &wait_status, 0);
    }

    return 0;
}
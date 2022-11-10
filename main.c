#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/personality.h>
#include <unistd.h>
#include "debugger.h"
#include "command_parser.h"

int main(int argc, char** argv)
{
    pid_t child_pid;

    if (argc < 2)
     {
        fprintf(stderr, "Expected a program name as argument\n");
        return -1;
    }

    child_pid = fork();

    if (child_pid == 0)
    {
        run_target(argv[1]);
    }
    else if (child_pid > 0)
        run_debugger(child_pid);
    else 
    {
        perror("fork");
        return -1;
    }

    return 0;
}
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <unistd.h>

struct break_point;

typedef struct break_point BREAK_POINT;


void run_debugger(pid_t child_pid);
void run_target(const char* programname);
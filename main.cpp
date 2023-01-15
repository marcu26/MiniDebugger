#include <unistd.h>
#include <sys/personality.h>

#include "debugger.hpp"

#pragma region utils

void execute_debugee (const std::string& prog_name) 
{
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) {
        std::cerr << "Error in ptrace\n";
        return;
    }
    execl(prog_name.c_str(), prog_name.c_str(), nullptr);
}
#pragma endregion


int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Program name not specified";
        return -1;
    }

    auto prog = argv[1];

    auto pid = fork();

    if (pid == 0) 
    {
        personality(ADDR_NO_RANDOMIZE);
        execute_debugee(prog);
    }

    else if (pid >= 1)  
    {
        std::cout << "Started debugging process " << pid << '\n';
        debugger dbg{prog, pid};
        dbg.run();
    }
}
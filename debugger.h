#include <iostream>

class Debugger
{
public:
    Debugger (std::string ProgName, pid_t Pid) :
     ProgName{std::move(ProgName)}, 
     Pid{Pid} {}

    void run();
    void handle_command(const std::string& line);

private:
    std::string ProgName;
    pid_t Pid;

};
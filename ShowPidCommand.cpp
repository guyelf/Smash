//
// Created by student on 4/22/20.
//
#include "Commands.h" // to be replaced with ShowPidCommand.h


ShowPidCommand::ShowPidCommand(const char* cmd_line):BuiltInCommand(cmd_line)
{

}

//takes the pid using the builtIn function
void  ShowPidCommand::execute()  {
    int smash_pid = ::getpid(); // Todo: Make sure it's the smash's Pid and not the SHELL's !!!
    std::cout << "smash pid is " + smash_pid << std::endl;
}



//
// Created by student on 4/22/20.
//
#include "Commands.h" // to be replaced with ShowPidCommand.h


ShowPidCommand::ShowPidCommand(const char* cmd_line):BuiltInCommand(cmd_line)
{

}

//takes the pid using the builtIn function
void  ShowPidCommand::execute()  {
    auto &smash = SmallShell::getInstance();
    int smash_pid = smash.pid;
    std::cout << "smash pid is " << to_string(smash_pid) << std::endl;
}



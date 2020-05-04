//
// Created by student on 4/22/20.
//
#include "Commands.h"

GetCurrDirCommand::GetCurrDirCommand(const char *cmd_line):BuiltInCommand(cmd_line) {}
void GetCurrDirCommand::execute() {
    std::string pwd  = ::getcwd(nullptr,0);
    std::cout<< pwd << std::endl; //print the pwd to the screen
}

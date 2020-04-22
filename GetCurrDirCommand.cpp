//
// Created by student on 4/22/20.
//
#include "Commands.h"

GetCurrDirCommand::GetCurrDirCommand(const char *cmd_line):BuiltInCommand(cmd_line) {}
void GetCurrDirCommand::execute() {
    char* pwd  = nullptr;
    ::getcwd(pwd,0); // should allocate the correct size itself, based on documentation
    std::cout<< pwd << std::endl; //print the pwd to the screen
    delete pwd;
}

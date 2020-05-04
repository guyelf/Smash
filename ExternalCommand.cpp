//
// Created by student on 4/29/20.
//
#include "Commands.h"

ExternalCommand::ExternalCommand(const char *cmd_line):Command(cmd_line),cmd(cmd_line),isFg(false){
    if(cmd.find("&") == std::string::npos){ //e.g no & sign
        this->isFg = true;
    }

}

void ExternalCommand::execute() {

 doExecvp(this->cmd.c_str()); //consider dropping the & ---> this should run in the bg

}



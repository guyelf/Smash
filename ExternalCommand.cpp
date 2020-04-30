//
// Created by student on 4/29/20.
//
#include "Commands.h"
#include "Commands.cpp"

ExternalCommand::ExternalCommand(const char *cmd_line):Command(cmd_line),isFg(false){
    if(cmd.find("&") == std::string::npos){ //e.g no & sign
        this->isFg = true;
    }

}

void ExternalCommand::execute() {
    char ** argv;
    _parseCommandLine(this->cmd.c_str(),argv); //assign the args
    int pid = doFork();
    if(pid == 0){ //son process
        std:string shellPath = "/bin/bash";
        execvp(shellPath.c_str(),argv);
    }
    else{
        if(this->isFg){ //if this is a foreground process father should wait
            wait(nullptr);
        }
    }
}



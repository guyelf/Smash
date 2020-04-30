//
// Created by student on 4/29/20.
//
#include "Commands.h"
#include "Commands.cpp"

ExternalCommand::ExternalCommand(const char *cmd_line):Command(cmd.c_str()),cmd(cmd_line),isFg(false){
    if(cmd.find("&") == std::string::npos){ //e.g no & sign
        this->isFg = true;
    }

}

void ExternalCommand::execute() {
    char ** argv;
    std::string shellPath = "/bin/bash";
    std::string full_cmd = shellPath + "-c" + this->cmd;
    _parseCommandLine(full_cmd.c_str(),argv); //assign the args
    int pid = doFork();
    if(pid == 0){ //son process
        execvp(shellPath.c_str(),argv); //if shit starts to be buggy consider dropping -c flag (telling the shell to run this char* as a command)
    }
    else{
        if(this->isFg){ //if this is a foreground process father should wait
            wait(nullptr);
        }

    }
}



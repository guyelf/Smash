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

    int ampSign = this->cmd.find("&");
    string noAmp = this->cmd;
    string tmp = this->cmd; //helper
     if(ampSign != std::string::npos){
          noAmp = tmp.substr(0,ampSign); //assumes & is the last char
     }


     auto &smash = SmallShell::getInstance();
     pid_t pid = doFork();
     if(pid == 0){//child

         doExecvp(noAmp.c_str()); //consider dropping the & ---> this should run in the bg
     }
     else{
         if(this->isFg){
             smash.fg_job->setpid(pid);
         }
         doWaitPID(pid); //might also stop at ctrl+z
     }
}



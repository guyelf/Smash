//
// Created by student on 4/23/20.
//

#include <fcntl.h>
#include <wait.h>
//#include <sys/wait.h>
#include "Commands.h"

RedirectionCommand::RedirectionCommand(const char *cmd_line):Command(cmd_line){

    int numSigns = 0;
    int i = 0;
    this->current_cmd.append(cmd_line);

    while(*cmd_line){
        if((*cmd_line) == '>'){
            numSigns++;
            this->sign_index = i; //stores the index of the > symbol
        }
        else
            i++; //don't advance i if you're on the sign
        cmd_line++;
    }
    this->r_type = numSigns == 1 ? ONE_REDIRECTION : TWO_REDIRECTIONS;
}

void RedirectionCommand::execute() {
    std::string cmd1 = this->current_cmd.substr(0,this->sign_index); // gets the command before the '>'
    std::string output; // output to be routed from the command
    SmallShell &smash = SmallShell::getInstance();

    int pid = doFork();
    if(pid == 0) {//son
        close(1);//stdOUT
        if (this->r_type == ONE_REDIRECTION) { // ">"
            output = this->current_cmd.substr(this->sign_index + 1); // gets the file to write to after the '>'
            open(output.c_str(), O_WRONLY | O_TRUNC | O_CREAT, 0666);

            smash.executeCommand(cmd1.c_str()); //run the command
        }
        else if (this->r_type == TWO_REDIRECTIONS) { // ">>"
            output = this->current_cmd.substr(this->sign_index + 2);
            open(output.c_str(), O_APPEND | O_RDWR|O_CREAT , 0666);
            SmallShell &smash = SmallShell::getInstance();
            smash.executeCommand(cmd1.c_str());
        }
        exit(0);
    }
    else
        if(!this->isBg){//fg
            smash.fg_job->setpid(pid);
        }

    doWaitPID(pid);
}


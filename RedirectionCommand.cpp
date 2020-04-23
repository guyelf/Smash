//
// Created by student on 4/23/20.
//

#include <fcntl.h>
#include <sys/wait.h>
#include "RedirectionCommand.h"

RedirectionCommand::RedirectionCommand(const char *cmd_line):Command(cmd_line) {

    int numSigns = 0;
    int i = 0;
    this->cmd.append(cmd_line);

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
    std::string cmd1 = this->cmd.substr(0,this->sign_index); // gets the command before the '>'
    std::string output; // output to be routed from the command
    int pid = doFork();
    if(pid == 0) {//son
        close(1);//stdOUT
        if (this->r_type == ONE_REDIRECTION) { // ">"
            output = this->cmd.substr(this->sign_index + 1); // gets the file to write to after the '>'
            open(output.c_str(), O_CREAT | O_WRONLY, 0555); //should create the file with r&w permissions to everyone
            SmallShell &smash = SmallShell::getInstance();
            smash.executeCommand(cmd1.c_str()); //run the command
        }
        else if (this->r_type == TWO_REDIRECTIONS) { // ">>"
            output = this->cmd.substr(this->sign_index + 2);
            open(output.c_str(), O_CREAT | O_APPEND, 0555); //should create the file with r&w permissions to everyone
            SmallShell &smash = SmallShell::getInstance();
            smash.executeCommand(cmd1.c_str());
        }
    }
    else
        waitpid(pid, nullptr,WNOHANG); //maybe the father needs more
}


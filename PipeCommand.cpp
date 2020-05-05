//
// Created by student on 4/23/20.
//

#include "Commands.h"

PipeCommand::PipeCommand(const char *cmd_line):Command(cmd_line),cmd_line(cmd_line){

    this->split_index = this->cmd_line.find("|&");

    if(this->split_index == std::string::npos){
        this->split_index = this->cmd_line.find("|");
        this->isAmp = false;
    }
    else{
        this->isAmp = true;
    }

}

PipeCommand::~PipeCommand(){}

void PipeCommand::execute() {

    //setting up args to fit this command expectations
    string cmd1 = this->cmd_line.substr(0,this->split_index);
    string cmd2 = this->cmd_line.substr(this->split_index+1);// w/o the delimiter
    //passing them accordingly

    SmallShell& smash = SmallShell::getInstance();
    auto main_pipe_pid = doFork();
    if(main_pipe_pid == 0){ // here run the commands as child process
        int pipe_fds[2];
        doPipe(pipe_fds); //create the pipe
        auto cmd1_pid = doFork();
        if(cmd1_pid == 0){ //the writing command
            int fd = (this->isAmp) ?  2 : 1; //assigns the correct fd based on the command
            doDup2(pipe_fds[1],fd);
            doClose(pipe_fds[1]);
            doClose(pipe_fds[0]);
            auto command1 = smash.CreateCommand(cmd1.c_str());
            command1->execute();
            delete command1;
            exit(0);
        }
        auto cmd2_pid = doFork();
        if(cmd2_pid == 0){ // the reading command
            doDup2(pipe_fds[0],0);
            doClose(pipe_fds[0]);
            doClose(pipe_fds[1]);
            auto command2 = smash.CreateCommand(cmd2.c_str());
            command2->execute();
            exit(0);
        }
        doClose(pipe_fds[0]);
        doClose(pipe_fds[1]);
        doWaitPID(cmd1_pid);
        doWaitPID(cmd2_pid);
        exit(0);
    }
    else{ //here wait for the childes to complete
        if(!this->isBg){//fg
            smash.fg_job->setpid(main_pipe_pid);
        }
        doWaitPID(main_pipe_pid);
    }

}

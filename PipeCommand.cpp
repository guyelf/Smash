//
// Created by student on 4/23/20.
//

#include "Commands.h"
#include <unistd.h>

PipeCommand::PipeCommand(const char *cmd_line):Command(cmd_line),cmd_line(cmd_line){}

PipeCommand::~PipeCommand(){}

void PipeCommand::execute() {
    std::vector<string> args = _parseCommandLineStrings(cmd_line.c_str());
    if ( args[1].compare("|&")){
        execute_amp(args);
    }
    else { //args[1] == "|"
       execute_pipe(args);
    }
}

void PipeCommand::execute_pipe(std::vector<string> args){
    int pipes[2];
    int pid = doFork();
    if (pid == 0){ //Command2
        pipe(pipes);
        close(0);
        dup2(pipes[0],0);
        close(pipes[0]);
        close(pipes[1]);
        SmallShell &smash = SmallShell::getInstance();
        smash.CreateCommand(args[2].c_str())->execute();
    }
    else{ //Command1
        pipe(pipes);
        close(1);
        dup2(pipes[1],1);
        close(pipes[0]);
        close(pipes[1]);
        SmallShell &smash = SmallShell::getInstance();
        smash.CreateCommand(args[0].c_str())->execute();
    }
}

void PipeCommand::execute_amp(std::vector<string> args){
    int pipes[2];
    int pid = doFork();
    if (pid == 0){ //Command2
        pipe(pipes);
        close(0);
        dup2(pipes[0],0);
        close(pipes[0]);
        close(pipes[1]);
        SmallShell &smash = SmallShell::getInstance();
        smash.CreateCommand(args[2].c_str())->execute();
    }
    else{ //Command1
        pipe(pipes);
        close(2);
        dup2(pipes[1],2);
        close(pipes[0]);
        close(pipes[1]);
        SmallShell &smash = SmallShell::getInstance();
        smash.CreateCommand(args[0].c_str())->execute();
    }
}
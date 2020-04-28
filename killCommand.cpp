//
// Created by student on 4/28/20.
//
//
// Created by student on 4/27/20.
//
#ifndef SMASH_KILLCOMMAND_H
#define SMASH_KILLCOMMAND_H
#include "Commands.cpp"
#include "MyExceptions.h"

KillCommand::KillCommand(const char *cmd_line) :BuiltInCommand(cmd_line){
    //todo: if we decide to go with a global (&static) jobs list
}


KillCommand::KillCommand(const char* cmd_line, JobsList* jobs):BuiltInCommand(cmd_line){

    auto args = _parseCommandLineStrings(cmd_line);
    if(args.size() != 3)
        throw MyKillCommandException("invalid arguments");

    int j_id =  stoi(args[2]); //string to int helper

    if(!jobs->getJobById(j_id)) // TODO: assumption - this return 0 if not found
        throw MyKillCommandException(j_id);

    this->j_pid = jobs->getJobById(j_id)->pid;

    this->signum = stoi(args[1]);
    if(signum<1 || signum > 31)
        throw MyKillCommandException("invalid arguments");
}

void KillCommand::execute() {
    int res = kill(this->j_pid,this->signum);
    if(res < 0)
        throw MyException("kill");

    cout << "signal number " << this->signum << " was sent to pid " << this->j_pid << endl;
}


#endif //SMASH_KILLCOMMAND_H


//
// Created by student on 4/28/20.
//
//
// Created by student on 4/27/20.
//
#ifndef SMASH_KILLCOMMAND_H
#define SMASH_KILLCOMMAND_H

#include "Commands.h"
#include "MyExceptions.h"

KillCommand::KillCommand(const char* cmd_line, JobsList* jobs):BuiltInCommand(cmd_line){
    auto args = _parseCommandLineStrings(cmd_line);

    if(args.size() != 3 && args[1].c_str()[0] == '-') //A check that - is the begging of the 2nd argument
        throw MyKillCommandException("invalid arguments");

    int j_id =  stoi(args[2]); //string to int helper

    if(jobs->getJobById(j_id) == nullptr)
        throw MyKillCommandException(j_id);

    this->j_pid = jobs->getJobById(j_id)->getpid();

    this->signum = stoi(args[1]);
    if(signum<1 || signum > 31)
        throw MyKillCommandException("invalid arguments");
}

KillCommand::~KillCommand(){}

void KillCommand::execute() {

    int res = kill(this->j_pid,this->signum);
    if(res < 0)
        throw MyException("kill");

    cout << "signal number " << this->signum << " was sent to pid " << this->j_pid << endl;
}


#endif //SMASH_KILLCOMMAND_H


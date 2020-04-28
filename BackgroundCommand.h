//
// Created by student on 4/27/20.
//

#ifndef SMASH_BACKGROUNDCOMMAND_H
#define SMASH_BACKGROUNDCOMMAND_H

#include "Commands.h"
#include "Commands.cpp"

BackgroundCommand::BackgroundCommand(const char *cmd_line, JobsList *jobs):BuiltInCommand(cmd_line),_job_id(-1){
 //todo: handle all 4 possible exceptions - there's a smart way to do that using inheritance we'll wait for the project to get bigger
    auto args = _parseCommandLineStrings(cmd_line);
    //todo handle exceptions

    if(args.size() == 2)
        this->_job_id = stoi(args[1]);

    this->_jobsList = jobs;
}

void BackgroundCommand::execute() {
    int j_id = this->_job_id;

    if(this->_job_id == -1) //if no job id was provided
        j_id = this->_jobsList->getTopJobId();

    auto jobToBg = this->_jobsList->getJobById(j_id);
    cout<< jobToBg->command + " : " + jobToBg->pid;
    kill(jobToBg->pid,SIGCONT);
    this->_jobsList->removeStoppedSign(j_id);

}

BackgroundCommand::~BackgroundCommand()  {
    free(this->_jobsList);
}

#endif //SMASH_BACKGROUNDCOMMAND_H

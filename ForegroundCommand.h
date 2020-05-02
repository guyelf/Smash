//
// Created by student on 4/27/20.
//

#ifndef SMASH_FOREGROUNDCOMMAND_H
#define SMASH_FOREGROUNDCOMMAND_H
#include "Commands.cpp"
#include "Commands.h"

ForegroundCommand::ForegroundCommand(const char* cmd_line, JobsList* jobs):BuiltInCommand(cmd_line),_job_id(-1){
    auto args = _parseCommandLineStrings(cmd_line);

    //invalid args: any invalid args should be caught and handled here
    if(args.size()>2)
       throw MyException("fg: invalid arguments");

    if (args.size() == 1 && jobs->size() == 0)
        throw MyException("fg: jobs list is empty");
    /*if(args.size()==2 && jobs->getJobById(stoi(args[1]))){ //meaning there's a job_id assigned and it's not found
       //todo: once Carmel finishes with the jobs list check if that job_id exists
       //todo: and throw an exception
    }
     */
    if(args.size() == 2)
        this->_job_id = stoi(args[1]);

    this->_jobsList = jobs;
}


void ForegroundCommand::execute() {
    int j_id = this->_job_id;

    if(this->_job_id == -1) //if no job id was provided
        j_id = this->_jobsList->getTopJobId();

    auto jobToFg = this->_jobsList->getJobById(j_id);

    cout<< jobToFg->command + " : " + jobToFg->pid << endl; //print the job like asked to
    kill(jobToFg->pid,SIGCONT);
    this->_jobsList->removeJobById(j_id); //removing the job after bringing it back to FG //todo: handle what if someone stops it again -> ctrl+c
    waitpid(jobToFg->pid,nullptr); //wait for that job to finish bc it's FG now.
}

ForegroundCommand::~ForegroundCommand() {
    free(this->_jobsList);
}


#endif //SMASH_FOREGROUNDCOMMAND_H

//
// Created by student on 4/28/20.
//

#include "Commands.h"

ForegroundCommand::ForegroundCommand(const char* cmd_line, JobsList* jobs):BuiltInCommand(cmd_line),_job_id(-1){
    vector<string> args = _parseCommandLineStrings(cmd_line);

    //invalid args: any invalid args should be caught and handled here
    if(args.size()>2)
        throw MyFgException("invalid arguments");

    if(args.size() == 2){
        try{ //checking format for the args
            int jobId = stoi(args[1]);
        }
        catch (exception &e) {
            throw MyFgException("invalid arguments");
        }

        this->_job_id = stoi(args[1]);
    }

    if (args.size() == 1 && jobs->size()==0)
        throw MyFgException("jobs list is empty");

    if(args.size()==2 && jobs->getJobById(stoi(args[1])) == nullptr){ //meaning there's a job_id assigned and it's not found
        throw MyFgException(stoi(args[1]));
    }

    this->_jobsList = jobs;
}


void ForegroundCommand::execute() {
    int j_id = this->_job_id;

    if(j_id == -1) //if no job id was provided
        j_id = this->_jobsList->getTopJobId();

     JobEntry *jobToFg = this->_jobsList->getJobById(j_id);
     string tmp = _trim(jobToFg->getcommand()->cmd_string());

     cout<< tmp << " : " << to_string(jobToFg->getpid()) << endl; //print jothe job like asked to

     int res = kill(jobToFg->getpid(),SIGCONT);
     //doKill(jobToFg->getpid(),SIGCONT);

     this->_jobsList->removeJobById(j_id); //removing by setting out = true;

     auto smash = &SmallShell::getInstance();
     smash->fg_job = jobToFg;

     doWaitPID(jobToFg->getpid(),WUNTRACED); //wait for that job to finish bc it's FG now.
    cout << "Hello World"<< endl;
}

ForegroundCommand::~ForegroundCommand() {
    free(this->_jobsList);
}




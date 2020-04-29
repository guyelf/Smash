//
// Created by student on 4/28/20.
//

#include "Commands.h"
#include "Commands.cpp"

BackgroundCommand::BackgroundCommand(const char *cmd_line, JobsList *jobs):BuiltInCommand(cmd_line),_job_id(-1){

    auto args = _parseCommandLineStrings(cmd_line);

    if(args.size()>2)
        throw MyBgException("invalid arguments");

    if (args.size() == 1 && jobs->size()==0)
        throw MyBgException("jobs list is empty");
    if(args.size()==2 && !jobs->getJobById(stoi(args[1]))){ //meaning there's a job_id assigned and it's not found
        //this IF assumes that getJobById returns 0 if the jobId is not found
        throw MyBgException(stoi(args[1]),"does not exist"); //overload for c'tor to throw with the job id - I'm so smart XD
    }
    if(args.size() == 2)//Todo: add correct checks after merging with Carmel's code
        //todo: use case the job exist (based on the job id) but is already running in the BG
        throw MyBgException(stoi(args[1]),"is already running in the background");

    int* tmpStopedId;
    jobs->getLastStoppedJob(tmpStopedId);
    if(tmpStopedId == nullptr){//e.g no stopped jobs
        throw MyBgException("there is no stopped jobs to resume");
    }
    free(tmpStopedId);
    //Finished handling exceptions

    if(args.size() == 2)
        this->_job_id = stoi(args[1]);

    this->_jobsList = jobs;
}

void BackgroundCommand::execute() {
   try{
       int j_id = this->_job_id;

       if(this->_job_id == -1) //if no job id was provided
           j_id = this->_jobsList->getTopJobId();

       auto jobToBg = this->_jobsList->getJobById(j_id);
       cout<< jobToBg->command + " : " + jobToBg->pid;
       kill(jobToBg->pid,SIGCONT);
       this->_jobsList->removeStoppedSign(j_id);

   }
   catch (std::exception& e) {
        throw MyException("bg");
   }
}

BackgroundCommand::~BackgroundCommand()  {
    free(this->_jobsList);
}



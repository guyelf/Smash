//
// Created by student on 4/28/20.
//

#include "Commands.h"

BackgroundCommand::BackgroundCommand(const char *cmd_line, JobsList *jobs):BuiltInCommand(cmd_line),_job_id(-1){

    auto args = _parseCommandLineStrings(cmd_line);

    if(args.size()>2)
        throw MyBgException("invalid arguments");

    try{
        if(args.size() == 2)
            int jobId = stoi(args[1]);
    }
    catch(exception& e){
        throw MyBgException("invalid arguments");
    }


    if (args.size() == 1 && jobs->size()==0)
        throw MyBgException("jobs list is empty");


    if(args.size()==2 && jobs->getJobById(stoi(args[1])) == nullptr){ //meaning there's a job_id assigned and it's not found
        throw MyBgException(stoi(args[1]),"does not exist"); //overload for c'tor to throw with the job id - I'm so smart XD
    }
    if(args.size() == 2 && !jobs->isJobStopped(stoi(args[1]))) //if the job is not stopped but is in the list
        throw MyBgException(stoi(args[1]),"is already running in the background");


    auto last_stopped_job = jobs->getLastStoppedJob(nullptr);
    if(last_stopped_job == nullptr){//e.g no stopped jobs
        throw MyBgException("there is no stopped jobs to resume");
    }
    //Finished handling exceptions

    if(args.size() == 2)
        this->_job_id = stoi(args[1]);

    this->_jobsList = jobs;
}

void BackgroundCommand::execute() {
       int j_id = this->_job_id;
       JobEntry* jobToBg;//the job that will be running in the BG (switched from stop)

       if(this->_job_id == -1) //if no job id was provided
          jobToBg = this->_jobsList->getLastStoppedJob(&j_id);
       else
           jobToBg = this->_jobsList->getJobById(j_id);

       cout<< jobToBg->getcommand()->cmd_string() << " : "  << std::to_string(jobToBg->getpid()) << endl;
       doKill(jobToBg->getpid(),SIGCONT); //might actually do here what i want it to do (as opposed to fg)
       this->_jobsList->removeStoppedSign(j_id);

}

BackgroundCommand::~BackgroundCommand()  {
    free(this->_jobsList);
}



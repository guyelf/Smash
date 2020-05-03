//
// Created by student on 4/28/20.
//

#include "Commands.h"

BackgroundCommand::BackgroundCommand(const char *cmd_line, JobsList *jobs):BuiltInCommand(cmd_line),_job_id(-1){

    auto args = _parseCommandLineStrings(cmd_line);

    if(args.size()>2)
        throw MyBgException("invalid arguments");

    if (args.size() == 1 && jobs->size()==0)
        throw MyBgException("jobs list is empty");

    if(args.size()==2 && jobs->getJobById(stoi(args[1])) == nullptr){ //meaning there's a job_id assigned and it's not found
        throw MyBgException(stoi(args[1]),"does not exist"); //overload for c'tor to throw with the job id - I'm so smart XD
    }
    if(args.size() == 2 && !jobs->isJobStopped(stoi(args[1]))) //if the job is not stopped but is in the list
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
       JobEntry* jobToBg;//the job that will be running in the BG (switched from stop)

       if(this->_job_id == -1) //if no job id was provided
          jobToBg = this->_jobsList->getLastStoppedJob(&j_id);
       else
           jobToBg = this->_jobsList->getJobById(j_id);

       cout<< jobToBg->getcommand()->cmd_string() << " : " + jobToBg->getpid() << endl;
       kill(jobToBg->getpid(),SIGCONT);
       this->_jobsList->removeStoppedSign(j_id);
   }
   catch (std::exception& e) {
        throw MyException("bg");
   }
}

BackgroundCommand::~BackgroundCommand()  {
    free(this->_jobsList);
}



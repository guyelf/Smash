//
// Created by student on 4/28/20.
//

#include "Commands.h"

ForegroundCommand::ForegroundCommand(const char* cmd_line, JobsList* jobs):BuiltInCommand(cmd_line),_job_id(-1){
    auto args = _parseCommandLineStrings(cmd_line);

    //invalid args: any invalid args should be caught and handled here
    if(args.size()>2)
        throw MyFgException("invalid arguments");

    if (args.size() == 1 && jobs->size()==0)
        throw MyFgException("jobs list is empty");
    if(args.size()==2 && jobs->getJobById(stoi(args[1]))){ //meaning there's a job_id assigned and it's not found
        throw MyFgException(stoi(args[1])); //overload for c'tor to throw with the job id - I'm so smart XD
    }

    if(args.size() == 2)
        this->_job_id = stoi(args[1]);

    this->_jobsList = jobs;
}


void ForegroundCommand::execute() {

    try{
        int j_id = this->_job_id;

        if(this->_job_id == -1) //if no job id was provided
            j_id = this->_jobsList->getTopJobId();

        auto jobToFg = this->_jobsList->getJobById(j_id);

        cout<< jobToFg->getcommand()->cmd_string() << " : " + to_string(jobToFg->pid) << endl; //print the job like asked to
        kill(jobToFg->pid,SIGCONT);
        this->_jobsList->removeJobById(j_id); //removing the job after bringing it back to FG //todo: handle what if someone stops it again -> ctrl+c
        //todo: how can I make sure smash is running it on the FG
        waitpid(jobToFg->pid,nullptr); //wait for that job to finish bc it's FG now.
    }
    catch (std::exception& e) {
        throw MyException("fg"); // for generic fg failure as instructed in the Error handling part
    }
}

ForegroundCommand::~ForegroundCommand() {
    free(this->_jobsList);
}




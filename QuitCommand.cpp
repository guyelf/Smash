//
// Created by student on 4/29/20.
//

#include "Commands.h"

QuitCommand::QuitCommand(const char *cmd_line, JobsList *jobs):BuiltInCommand(cmd_line),_killFlag(false) {
    auto args = _parseCommandLineStrings(cmd_line);
    this->_jobsList = jobs;
    if(args.size() == 2 && args[1].compare("kill")==0)
        this->_killFlag = true;
}

void QuitCommand::execute() {

    SmallShell& smash = SmallShell::getInstance();
    if(this->_killFlag){ //kill flag is true
        int numJobs = this->_jobsList->size();
        cout<< "sending SIGKILL signal to " << to_string(numJobs) << " jobs:" << endl;

        //for(list<JobEntry>::iterator current = this->_jobsList.; current != this->jobs_list.end() ; current++){


        for (int i = 0; i < numJobs; ++i) { //deletes the top_job each iteration
            int top_job_id = this->_jobsList->getTopJobId();

        }
        this->_jobsList->killAllJobs();
        doKill(smash.pid,SIGKILL); //kill smash
    }
}

QuitCommand::~QuitCommand() {
    free(this->_jobsList);
}

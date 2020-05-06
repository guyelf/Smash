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
        if (this->_jobsList->size() == 0) {
            cout << "sending SIGKILL signal to " << to_string(this->_jobsList->size()) << " jobs:" << endl;
        }
        if (this->_jobsList->size() > 0) {
            cout << "sending SIGKILL signal to " << to_string(this->_jobsList->size()) << " jobs:" << endl;
            this->_jobsList->killAllJobs();
        }
    }
    else{ //kill flag is false
        this->_jobsList->killAllJobs_no_print();
    }
    //int res = waitPid(smash.pid,WNOHANG);
    kill(smash.pid,SIGKILL); //kill smash
}

QuitCommand::~QuitCommand() {
    free(this->_jobsList);
}

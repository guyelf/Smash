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
        cout<< "sending SIGKILL signal to " << to_string(this->_jobsList->size()) << " jobs:" << endl;
        this->_jobsList->killAllJobs();
        doKill(smash.pid,SIGKILL); //kill smash
    }
}

QuitCommand::~QuitCommand() {
    free(this->_jobsList);
}

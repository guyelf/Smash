#include <iostream>
#include <signal.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num) {
    cout << "smash: got ctrl-Z" << endl;
    string res = "smash: process";
    pid_t pid_process = ::getpid();
    SmallShell& smash = SmallShell::getInstance();
    if (smash.pid == pid_process){
        kill(pid_process,SIGSTOP);
        res = res + to_string(pid_process) + "was stopped";
        if (!smash.stopProcess(pid_process)){
            int newjobid = smash.getTopJobId() +1;
            smash.setCurrentJobId(newjobid);
            //smash.addCurrentJob();
        }
        cout<< res << endl;
    }
    else{

    }
}

void ctrlCHandler(int sig_num) {
    cout << "smash: got ctrl-C" << endl;
    string res = "smash: process";
    pid_t pid_proccess = ::getpid();
    SmallShell& smash = SmallShell::getInstance();
    if (smash.pid != pid_proccess){
        kill(pid_proccess,SIGKILL);
        smash.killProcess(pid_proccess);
        res = res + to_string(pid_proccess) + "was killed";
        cout<< res << endl;
    }
}

void alarmHandler(int sig_num) {
    cout << "smash got an alarm" << endl;
}


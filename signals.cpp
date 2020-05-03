#include <iostream>
#include <signal.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num) {
    SmallShell& smash = SmallShell::getInstance();
    pid_t pid_process = ::getpid();
    if (pid_process != smash.pid){
        return;
    }
    cout << "smash: got ctrl-Z" << endl;
    JobEntry *jb = smash.fg_job;
    if (!jb->getpid()){
        return;
    }
    if (!smash.isJobInList(jb->getpid())){
        smash.addJobToListZ(jb);
    }
    smash.setJobAsStopped(jb->getpid());
    string res = "smash: process ";
    kill(pid_process,SIGSTOP);
    res = res + to_string(pid_process) + " was stopped";
    cout << res << endl;
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


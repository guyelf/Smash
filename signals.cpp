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
    doKill(pid_process,SIGSTOP);
    res = res + to_string(pid_process) + " was stopped";
    cout << res << endl;
}

void ctrlCHandler(int sig_num) {
    SmallShell &smash = SmallShell::getInstance();
    cout << "smash: got ctrl-C" << endl;
    pid_t pid = smash.fg_job->getpid();
    if (pid) {
        string res = "smash: process";
        doKill(pid, SIGKILL);
        if (smash.isJobInList(pid)) {
            smash.killProcess(pid);
        }
        res = res + to_string(pid) + "was killed";
        cout << res << endl;
    }
}

void alarmHandler(int sig_num) {
    cout << "smash got an alarm" << endl;
}


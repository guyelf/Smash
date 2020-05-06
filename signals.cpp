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
    if (jb->getpid() <= 0){ //illegal pid , 0 is for the smash son
        return;
    }
    auto job_pid = jb->getpid();
    if (!smash.isJobInList(job_pid) || smash.fg_job->getpid()==0){//might be buggy if more than 1 fg process - replaces the fg
        smash.addJobToListZ(jb);
    }
    smash.setJobAsStopped(job_pid);
    string res = "smash: process ";
    doKill(job_pid,SIGSTOP);
    res = res.append(to_string(job_pid)).append(" was stopped");
    cout << res << endl;
    smash.fg_job = nullptr;
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


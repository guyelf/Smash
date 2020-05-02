#include <iostream>
#include <signal.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num) {
    cout << "smash: got ctrl-Z" << "\n";
    string res = "smash: process";
    pid_t pid_process = ::getpid();
    SmallShell& smash = SmallShell::getInstance();
    if (smash.pid != pid_process){
        kill(pid_process,SIGSTOP);
        res = res + to_string(pid_process) + "was stopped";
        if (!smash.stopProcess(pid_process)){
            Command *cmd = smash.CreateCommand(smash.last_cmd);
            smash.addCmd(cmd,pid_process);
        }
        cout<< res << "\n";
    }
}

void ctrlCHandler(int sig_num) {
    cout << "smash: got ctrl-C" << "\n";
    string res = "smash: process";
    pid_t pid_proccess = ::getpid();
    SmallShell& smash = SmallShell::getInstance();
    if (smash.pid != pid_proccess){
        kill(pid_proccess,SIGKILL);
        smash.killProcess(pid_proccess);
        res = res + to_string(pid_proccess) + "was killed";
        cout<< res << "\n";
    }
}

void alarmHandler(int sig_num) {
    cout << "smash got an alarm" << "\n";
}


//
// Created by student on 4/23/20.
//

#include "Wrappers.h"
#include "MyExceptions.h"


static bool isSmash(){
    return SmallShell::getInstance().pid == getpid();
}

int doFork() {
    SmallShell& smash = SmallShell::getInstance();
    bool isFg = (smash.pid == ::getpid());
    int child = fork();
    if(child < 0){
        throw MySystemCallException("fork");
    }
    else if (child == 0 && isFg) //if in the child and also forking from fg --> change parent_group
        ::setpgrp();
    return child;
}


void doExecvp(const char* command){
    const char* const args[4] = {"/bin/bash","-c",command, nullptr};
    execvp(args[0], const_cast<char* const*>(args));
    throw MySystemCallException("execvp");
}


void doChngDir(const char* newDir){
      if(chdir(newDir) == -1)
        throw MySystemCallException("chdir");
}

int doKill(pid_t pid, int signal){
    int val = killpg(pid,signal);
    if(val != 0)
        throw MySystemCallException("kill");
    return val;
}

int doClose(int fd){
    int res = close(fd);
    if(res == -1)
        throw MySystemCallException("close");
    return res;
}

pid_t doWaitPID(pid_t pid, int options){
    if(options != WNOHANG){
        if(isSmash()){
            options = WUNTRACED;
        }
        else{
            options = 0;
        }
    }
    if(pid == 0)
        return pid;
    return waitpid(pid,nullptr,options);
}



void doDup2(int fd, int received_fd){
    if(dup2(fd,received_fd) == -1){//e.g fails
        throw MySystemCallException("dup2");
    }
}

//Todo: why was it MyException beforehand?
void doPipe(int *p_des){
    if(pipe(p_des) == -1){ //e.g fails
        throw MySystemCallException("pipe");
    }
}



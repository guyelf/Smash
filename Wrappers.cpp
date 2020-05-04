//
// Created by student on 4/23/20.
//

#include "Wrappers.h"
#include "MyExceptions.h"

int doFork() {
    SmallShell& smash = SmallShell::getInstance();
    bool isFg = (smash.pid == ::getpid());
    int child = fork();
    if(child < 0){
        throw MyException("fork");
    }
    else if (child == 0 && isFg) //if in the child and also forking from fg --> change parent_group
        ::setpgrp();
    return child;
}


void doExecvp(const char* command){
    const char* const args[4] = {"/bin/bash","-c",command, nullptr};
    execvp(args[0], const_cast<char* const*>(args));
    throw MyException("execvp");
}


void doChngDir(const char* newDir){
      if(chdir(newDir) == -1)
        throw MyException("chdir");
}



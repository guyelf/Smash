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
        doPerror("fork");
        throw MySpecialCommandException();
    }
    else if (child == 0 && isFg) //if in the child and also forking from fg --> change parent_group
        ::setpgrp();
    return child;
}

void doPerror(char *sysCall_name) {
    // todo: find from where to get the syscall failed name (exception.what??)
    // todo: append the "failed"
    perror("smash error");
}



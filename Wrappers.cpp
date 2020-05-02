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




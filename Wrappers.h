//
// Created by student on 4/23/20.
//

#ifndef SMASH_WRAPPERS_H
#define SMASH_WRAPPERS_H
#include "Commands.h"
int doFork();
void doExecvp(const char* command);
void doChngDir(const char* newDir);
int doKill(pid_t pid, int signal);
int doClose(int fd);

#endif //SMASH_WRAPPERS_H

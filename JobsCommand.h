//
// Created by student on 4/22/20.
//


#ifndef SMASH_JOBSCOMMAND_H
#define SMASH_JOBSCOMMAND_H

#include "Commands.h"


class JobsCommand : public BuiltInCommand {
    // TODO: Add your data members
    list<JobsList> myJobs;
public:
    JobsCommand(const char* cmd_line, JobsList* jobs);
    virtual ~JobsCommand() {}
    void execute() override;
};
#endif //SMASH_JOBSCOMMAND_H

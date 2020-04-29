//
// Created by student on 4/22/20.
//
//assuming we have the JOBS Sturct
#include "JobsCommand.h"
JobsCommand::JobsCommand(const char *cmd_line, JobsList *jobs) :BuiltInCommand(cmd_line){
    //todo: run on the jobs list and clear all the finished ones
    //todo ?? assign them all to a list with while loop (list is better bc it sortable)
}

bool compareJobIds(JobEntry j1, JobEntry j2)
{
    return (j1.job_id < j2.job_id);
}

void JobsCommand::execute() {
    myJobs.sort(compareJobIds);
    for (int i = 0; i < myJobs.size(); ++i) {
        //iterate over all the sorted jobs
        // use their property of 'stopped' to know how to print each one
        //print them
        //cout<< "["+ job.job_id + "]"+ job.command+" : "+ job.pid + //either stopped or not
    }
}


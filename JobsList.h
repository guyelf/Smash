//
// Created by Dell on 30/04/2020.
//

#ifndef SMASH_JOBSLIST_H
#define SMASH_JOBSLIST_H

#include "Commands.h"
using namespace std;
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>


class JobsList {
    class JobEntry { //TODO move to public??
    public:
        Command *command;
        pid_t pid;
        int job_id;
        bool stopped;
        bool out;
        std::chrono::system_clock::time_point schedule_time;
        std::chrono::system_clock::time_point stop_time;
        // for getting the elapsed seconds use - std::chrono::duration<double> elapsed
        // TODO : How I get pid, which class is pid
        JobEntry(Command *command,pid_t pid,int job_id,std::chrono::system_clock::time_point time,bool stopped):command(command),
            pid(pid),job_id(job_id),schedule_time(time),stopped(stopped),out(false){};
        ~JobEntry();
        std::string print_job();
        void kill();
    };
    list<JobEntry> jobs_list;
    JobsList();
    ~JobsList();
    int size();
    void addJob(Command* cmd,pid_t pid,bool isStopped = false);
    void printJobsList();
    void killAllJobs(); //NEEDED TO BE COMPLETED
    void removeFinishedJobs(); //TODO
    JobEntry *getJobById(int jobId);
    void removeJobById(int jobId);
    JobEntry *getLastJob(int* lastJobId); //TODO
    JobEntry *getLastStoppedJob(int *jobId);
    int getTopJobId();
    void removeStoppedSign(int jobId);
    void stopJobById(int jobID);
    void setJobAsFinished(int jobId);
};


#endif //SMASH_JOBSLIST_H
//
// Created by Dell on 30/04/2020.
//

#include "JobsList.h"

JobsList::JobsList() {
    this->jobs_list = list<JobEntry>();
}
JobsList::~JobsList() {}

void JobsList::addJob(Command *cmd,pid_t pid,bool isStopped) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    int job_id = getTopJobId() +1;
    JobEntry new_job = JobEntry(cmd,pid,job_id,now,isStopped);
    this->jobs_list.assign(job_id,new_job);
}
std::string JobsList::JobEntry::print_job() {
    std::string res = "[" + to_string(job_id) + "]" + this->command->cmd_string() + " : " + to_string(this->pid);
    //TODO: add elapsed time!!
    return res;
}

int JobsList::size() {
    return this->jobs_list.size();
}
void JobsList::printJobsList() {
    removeFinishedJobs();
    for (list<JobEntry>::iterator current = this->jobs_list.begin();current != this->jobs_list.end();current++){
        if(current->out == false) {
            std::string res = current->print_job();
            cout << res << "\n";
        }
    }
}
void JobsList::killAllJobs() {
    for (list<JobEntry>::iterator  current = this->jobs_list.begin(); current!=this->jobs_list.end() ; current++) {
        JobEntry current_job = *current;
        this->jobs_list.erase(current);
        kill(current_job.pid,SIGKILL); //TODO
    }
}
JobsList::JobEntry * JobsList::getJobById(int jobId) {
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == jobId){
            JobEntry res = *current;
            return &res;
        }
    }
    return nullptr;
}

void JobsList::setJobAsFinished(int jobId){
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == jobId){
            if (waitpid(current->pid, nullptr,WNOHANG) > 0){
                this->jobs_list.erase(current);
            }
        }
    }
}

JobsList::JobEntry * JobsList::getLastJob(int *lastJobId) {
    std::chrono::system_clock::time_point time = this->jobs_list.begin()->schedule_time;
    JobEntry *lastjob = nullptr;
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->schedule_time > time){
            *lastJobId = current->job_id;
            *lastjob = *current;
        }
    }
    return lastjob;
}

void JobsList::removeFinishedJobs() {
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (waitpid(current->pid, nullptr,WNOHANG) > 0){
            this->jobs_list.erase(current);
        }
    }
}

void JobsList::removeStoppedSign(int jobId) {
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == jobId){
            current->stopped = false;
        }
    }
}

JobsList::JobEntry* JobsList::getLastStoppedJob(int *jobId) {
    std::chrono::system_clock::time_point current_last_stop_time = std::chrono::system_clock::now();
    bool found_stopped = false;
    JobEntry *last_stopped = nullptr;
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++) {
        if(current->stopped == true){
            found_stopped = true;
            if (current_last_stop_time > current->stop_time) {
                *jobId = current->job_id;
                *last_stopped = *current;
            }
        }
    }
    return last_stopped;
}

int JobsList::getTopJobId(){
    int max_id=this->jobs_list.begin()->job_id;
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id > max_id){
            max_id = current->job_id;
        }
    }
    return max_id;
}
void JobsList::stopJobById(int jobID){
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == jobID){
            current->stop_time = std::chrono::system_clock::now();
            current->stopped = true;
        }
    }
}

void JobsList::removeJobById(int jobId) {
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == jobId){
            current->out = true;
        }
    }
}

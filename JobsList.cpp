//
// Created by Dell on 30/04/2020.
//

#include "Commands.h"
#include <string>


JobsList::JobsList():size_(0){
    this->jobs_list = list<JobEntry>();
}

JobsList::~JobsList(){}

void JobsList::addJob(Command *cmd,pid_t pid,bool isStopped) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    int job_id = getTopJobId() +1;
    JobEntry new_job = JobEntry(cmd,pid,job_id,now,isStopped);
    this->jobs_list.push_back(new_job);
    this->size_ +=1;
}
std::string JobEntry::print_job() {
    std::string res = "[" + to_string(job_id) + "]" + this->command->cmd_string() + " : " + to_string(this->pid);
    std::chrono::duration<double> elapsed_time = std::chrono::system_clock::now() - this->schedule_time;
    res = res + " " + to_string(elapsed_time.count()) + " secs";
    if (this->stopped == true){
        res = res + " (stopped)";
    }
    return res;
}

int JobsList::size() {
    return this->jobs_list.size();
}
JobEntry* JobsList::getJobByPID(pid_t pid){
    JobEntry *je= nullptr;
    for (list<JobEntry>::iterator current = this->jobs_list.begin();current != this->jobs_list.end();current++){
        if (current->pid == pid){
            *je = *current;
        }
    }
    return je;
}

void JobsList::addJobZ(JobEntry *je){
    this->jobs_list.push_back(*je);
}

void JobsList::printJobsList() {
    removeFinishedJobs();
    this->jobs_list.sort(JobCompare());
    for (list<JobEntry>::iterator current = this->jobs_list.begin();current != this->jobs_list.end();current++){
        if(current->out == false) {
            std::string res = current->print_job();
            cout << res << "\n";
        }
    }

}
void JobsList::killAllJobs() {
    for (list<JobEntry>::iterator current = this->jobs_list.begin(); current!=this->jobs_list.end() ; current++) {
        JobEntry current_job = *current;
        this->jobs_list.erase(current);
        kill(current_job.pid,SIGKILL);
    }
}
JobEntry * JobsList::getJobById(int jobId) {
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

JobEntry * JobsList::getLastJob(int *lastJobId) {
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
    if ( !this->jobs_list.empty()) {
        for (list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end(); current++) {
            pid_t pid = waitpid(current->pid, nullptr, WUNTRACED);
            if ( !current->out &&  pid == current->pid) {
                current->out = true;
                this->size_ --;
            }
        }
    }
}

bool JobsList::isJobStopped(int job_id){
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == job_id){
            return current->stopped;
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

JobEntry* JobsList::getLastStoppedJob(int *jobId) {
    std::chrono::system_clock::time_point current_last_stop_time = std::chrono::system_clock::now();
    bool found_stopped = false;
    JobEntry *last_stopped = nullptr;
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++) {
        if( !current->out && current->stopped == true){
            found_stopped = true;
            if (current_last_stop_time > current->stop_time) {
                *jobId = current->job_id;
                *last_stopped = *current;
            }
        }
    }
    return last_stopped;
}
void JobEntry::setNewId(int newid){
    this->job_id = newid;
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

bool JobsList::stopJobByPID(int PID) {
    bool found = false;
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++) {
        if (current->pid == PID) {
            current->stop_time = std::chrono::system_clock::now();
            current->stopped = true;
            found = true;
        }
    }
    return found;

}
void JobsList::killJob(int PID) {
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->pid == PID){
            this->jobs_list.erase(current);
        }
    }
}


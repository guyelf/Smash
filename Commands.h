#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_

#include <vector>
#include <list>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <iterator>

#define COMMAND_ARGS_MAX_LENGTH (200)
#define COMMAND_MAX_ARGS (20)
#define HISTORY_MAX_RECORDS (50)

//my includes:
#include "Wrappers.h"
#include "MyExceptions.h"

using namespace std;

class JobsList;
class JobCompare;

class Command {
    const char * cmd;
 public:
  explicit Command(const char* cmd_line);
  virtual ~Command();
  virtual void execute() = 0;
  virtual const char* cmd_string()=0;
  //virtual void prepare();
  //virtual void cleanup();
  // TODO: Add your extra methods if needed
};

class BuiltInCommand : public Command {
    std::string cmd;
public:
  explicit BuiltInCommand(const char* cmd_line);
  virtual ~BuiltInCommand() {}
  const char* cmd_string() override { return this->cmd.c_str();}

  // Todo: Add generic error message function for sub class to derive from (page 2/18)
};

class ExternalCommand : public Command {
    std::string cmd;
    bool isFg;
 public:
  explicit ExternalCommand(const char* cmd_line);
  virtual ~ExternalCommand() {}
  void execute() override;
  const char* cmd_string() override { return this->cmd.c_str();}
};

class ChangeDirCommand : public BuiltInCommand {
private:
   static std::string prev_pwd; //all instances should have same prev
   std::vector<std::string> params;
   int num_params;
public:
  explicit ChangeDirCommand(const char* cmd_line);
  virtual ~ChangeDirCommand() {}
  void execute() override;

};

class GetCurrDirCommand : public BuiltInCommand {
std::string cmd;
public:
  explicit GetCurrDirCommand(const char* cmd_line);
  virtual ~GetCurrDirCommand() {}
  void execute() override;

};

class ShowPidCommand : public BuiltInCommand {
 public:
  explicit ShowPidCommand(const char* cmd_line);
  virtual ~ShowPidCommand() {}
  void execute() override;
};

//class JobsList;
class QuitCommand : public BuiltInCommand {
// TODO: Add your data members public:

    bool _killFlag;
    JobsList* _jobsList;
public:
  QuitCommand(const char* cmd_line, JobsList* jobs);
  virtual ~QuitCommand();
  void execute() override;
};
class JobsCommand : public BuiltInCommand{
    JobsList* myJobs;
public:
    JobsCommand(const char *cmd_line, JobsList *jobs): BuiltInCommand(cmd_line),myJobs(jobs){}
    virtual ~JobsCommand(){}
    void execute();
};


class ChangePrompt : public BuiltInCommand {
public:
    ChangePrompt(const char* cmd_line);
    virtual ~ChangePrompt();
    void execute() override;
};

class CommandsHistory {
 protected:
  class CommandHistoryEntry {
	  // TODO: Add your data members
  };
 // TODO: Add your data members
 public:
  CommandsHistory();
  ~CommandsHistory() {}
  void addRecord(const char* cmd_line);
  void printHistory();
};

class HistoryCommand : public BuiltInCommand {
 // TODO: Add your data members
 public:
  HistoryCommand(const char* cmd_line, CommandsHistory* history);
  virtual ~HistoryCommand() {}
  void execute() override;
};

class KillCommand : public BuiltInCommand {
    pid_t  j_pid; //job's pid
    int signum;
public:
    KillCommand(const char* cmd_line,JobsList* jobs);
    virtual ~KillCommand();
    void execute() override;
};

class ForegroundCommand : public BuiltInCommand {
 int _job_id;
 JobsList* _jobsList;
 public:
  ForegroundCommand(const char* cmd_line, JobsList* jobs);
  virtual ~ForegroundCommand();
  void execute() override;
};

class BackgroundCommand : public BuiltInCommand {
 int _job_id;
 JobsList* _jobsList;
 public:
    BackgroundCommand(const char* cmd_line, JobsList* jobs);
  virtual ~BackgroundCommand();
  void execute() override;
};

enum RedirectionType {ONE_REDIRECTION, TWO_REDIRECTIONS};
class RedirectionCommand : public Command {
    RedirectionType r_type;
    int sign_index;
    std::string current_cmd;
public:
    explicit RedirectionCommand(const char* cmd_line);
    void execute() override;
    const char* cmd_string() override { return this->current_cmd.c_str();}
    virtual ~RedirectionCommand() {}
    //void prepare() override;
    //void cleanup() override;
};

class CopyCommand : public Command {
    std::string cmd_line;
public:
  explicit CopyCommand(const char* cmd_line);
  virtual ~CopyCommand(){}
  void execute() override;
  const char* cmd_string() override { return this->cmd.c_str();}
};


// maybe chprompt-done on main , timeout ?

class PipeCommand : public Command {
    std::string cmd_line;
public:
    explicit PipeCommand(const char* cmd_line);
    virtual ~PipeCommand();
    const char* cmd_string() override { return this->cmd_line.c_str();}
    void execute() override;
    void execute_pipe(std::vector<string> args);
    void execute_amp(std::vector<string> args);
};

//Following the design pattern of a singleton classs
class JobEntry {
    friend JobsList;
    friend JobCompare;
    Command *command;
    pid_t pid;
    int job_id;
    bool stopped;
    bool out;
    std::chrono::system_clock::time_point schedule_time;
    std::chrono::system_clock::time_point stop_time;
public:
    JobEntry(Command *command,pid_t pid,int job_id,std::chrono::system_clock::time_point time,bool stopped):
            command(command),pid(pid),job_id(job_id),schedule_time(time),stopped(stopped),out(false){}
    ~JobEntry(){}
    pid_t getpid(){return this.pid;}
    Command* getcommand(){return this.command;}
    void setNewId(int newid);
    std::string print_job();
    void setJobAsStopped(){
        this.stopped = true;
    }
};

class JobsList {
    list<JobEntry> jobs_list;
public:
    JobsList();
    ~JobsList();
    int size();
    void addJob(Command* cmd,pid_t pid,bool isStopped = false);
    void printJobsList();
    void killAllJobs();
    void removeFinishedJobs();
    JobEntry *getJobById(int jobId);
    JobEntry removeJobById(int jobId);
    JobEntry *getLastJob(int* lastJobId);
    JobEntry *getLastStoppedJob(int *jobId);
    int getTopJobId();
    void removeStoppedSign(int jobId);
    void stopJobById(int jobID);
    void setJobAsFinished(int jobId);
    bool isJobStopped(int job_id);
    bool stopJobByPID(int PID);
    void killJob(int PID);
    JobEntry* getJobByPID(pid_t pid);
    void addJobZ(JobEntry *je);
};

class JobCompare{
public:
    JobCompare(){}
    ~JobCompare(){}
    int operator()(JobsList::JobEntry je1,JobsList::JobEntry je2);
};


class SmallShell {
    JobsList *jobs_list;
    SmallShell();

 public:
    JobEntry *fg_job;
    pid_t pid;
    const char* current_path;
    const char* last_cmd;
    Command *CreateCommand(const char* cmd_line);
    SmallShell(SmallShell const&)      = delete; // disable copy ctor
    void operator=(SmallShell const&)  = delete; // disable = operator
    static SmallShell& getInstance() // make SmallShell singleton
    {
    static SmallShell instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
  }
    ~SmallShell();
    void executeCommand(const char* cmd_line);
    bool setJobAsStopped(pid_t pid);
    void killProcess(pid_t pid);
    void addCmd(Command *cmd,int pid);
    int getTopJobId();
    void setCurrentJobId(int newJobId);
    bool isJobInList(pid_t pid);
    void addJobToListZ(JobEntry *je);
};

int _parseCommandLine(const char* cmd_line, char** args) {
    FUNC_ENTRY()
    int i = 0;
    std::istringstream iss(_trim(string(cmd_line)).c_str());
    for(std::string s; iss >> s; ) {
        args[i] = (char*)malloc(s.length()+1);
        memset(args[i], 0, s.length()+1);
        strcpy(args[i], s.c_str());
        args[++i] = NULL;
    }
    return i;

    FUNC_EXIT()
}

std::vector<string> _parseCommandLineStrings(const char* cmd_line) {
    char** f_args = nullptr;
    vector<string> args;
    _parseCommandLine(cmd_line,f_args);
    while(*f_args){
        args.push_back(*f_args);
        f_args++;
    }
    return args;
}




#endif //SMASH_COMMAND_H_

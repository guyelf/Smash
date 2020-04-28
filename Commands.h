#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_

#include <vector>
#include <list>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
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
#include "JobsCommand.h"
#include "RedirectionCommand.h"
#include "MyExceptions.h"
class Command {
    const char * cmd;
 public:
  explicit Command(const char* cmd_line);
  virtual ~Command();
  virtual void execute() = 0;
  virtual const char* cmd_string() =0;
  //virtual void prepare();
  //virtual void cleanup();
  // TODO: Add your extra methods if needed
};

class BuiltInCommand : public Command {
 public:
  explicit BuiltInCommand(const char* cmd_line);
  virtual ~BuiltInCommand() {}
  // TOdo: Add generic error message function for sub class to derive from (page 2/18)
};

class ExternalCommand : public Command {
 public:
  explicit ExternalCommand(const char* cmd_line);
  virtual ~ExternalCommand() {}
  void execute() override;
};

class ChangeDirCommand : public BuiltInCommand {
private:
   static std::string prev_pwd; //all instances should have same prev
   std::vector<std::string> params;
   int num_params;
public:
  ChangeDirCommand(const char* cmd_line, char** plastPwd);
  virtual ~ChangeDirCommand() {}
  void execute() override;
};

class GetCurrDirCommand : public BuiltInCommand {
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

class JobsList;
class QuitCommand : public BuiltInCommand {
// TODO: Add your data members public:

    bool _killFlag;
    JobsList* _jobsList;
public:
  QuitCommand(const char* cmd_line, JobsList* jobs);
  virtual ~QuitCommand();
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

class JobsList {
  class JobEntry { //TODO move to public??
  public:
      Command *command;
      pid_t pid;
      int job_id
      bool stopped;
      bool finished;
      std::chrono::system_clock::time_point schedule_time;
      std::chrono::system_clock::time_point stop_time;
      // for getting the elapsed seconds use - std::chrono::duration<double> elapsed
      // TODO : How I get pid, which class is pid
      JobEntry(Command *command,pid_t pid,int job_id,std::chrono::system_clock::time_point time,bool stopped):command(command),
      pid(pid),job_id(job_id),schedule_time(time),stopped(stopped),finished(false){};
      ~JobEntry();
      std::string print_job();
      void kill();
  };
 list<JobEntry> jobs_list;
 public:
    JobsList();
    ~JobsList();
    int size();
    void addJob(Command* cmd,pid_t pid,bool isStopped = false);
    void printJobsList();
    void killAllJobs(); //NEEDED TO BE COMPLETED
    void removeFinishedJobs(); //TODO
    JobEntry *getJobById(int jobId);void removeJobById(int jobId);
    JobEntry *getLastJob(int* lastJobId) //TODO
    JobEntry *getLastStoppedJob(int *jobId);
    int getTopJobId();
    void removeStoppedSign(int jobId);
    void stopJobById(int jobID);
    void setJobAsFinished(int jobId);
};
class KillCommand : public BuiltInCommand {
    // TODO: Add your data members
    pipid_t j_pid; //job's pid
    int signum;
public:
    explicit KillCommand(const char* cmd_line);
    KillCommand(const char* cmd_line, JobsList* jobs);
    virtual ~KillCommand() {}
    void execute() override;
};
class ForegroundCommand : public BuiltInCommand {
 // TODO: Add your data members
 int _job_id;
 JobsList* _jobsList;
 public:
  ForegroundCommand(const char* cmd_line, JobsList* jobs);
  virtual ~ForegroundCommand();
  void execute() override;
};

class BackgroundCommand : public BuiltInCommand {
 // TODO: Add your data members
 int _job_id;
 JobsList* _jobsList;
 public:
  BackgroundCommand(const char* cmd_line, JobsList* jobs);
  virtual ~BackgroundCommand();
  void execute() override;
};


// TODO: should it really inhirit from BuiltInCommand ?
class CopyCommand : public BuiltInCommand {
 public:
  CopyCommand(const char* cmd_line);
  virtual ~CopyCommand() {}
  void execute() override;
};

// TODO: add more classes if needed 
// maybe chprompt-done on main , timeout ?

//Following the design pattern of a singleton classs
class SmallShell {
 private:
  // TODO: Add your data members
  SmallShell();
 public:
  ppid_t pid;
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
  // TODO: add extra methods as needed
};


#endif //SMASH_COMMAND_H_

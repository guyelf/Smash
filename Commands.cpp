#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include <chrono>
#include "Commands.h"

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

#if 0
#define FUNC_ENTRY()  \
  cerr << __PRETTY_FUNCTION__ << " --> " << endl;

#define FUNC_EXIT()  \
  cerr << __PRETTY_FUNCTION__ << " <-- " << endl;
#else
#define FUNC_ENTRY()
#define FUNC_EXIT()
#endif

#define DEBUG_PRINT cerr << "DEBUG: "

#define EXEC(path, arg) \
  execvp((path), (arg));

JobsList::JobsList() {
    std::chrono::system_clock time= std::chrono::system_clock();
    this->jobs_list = list<JobEntry>();
}
JobsList::~JobsList() {}

void JobsList::addJob(Command *cmd, bool isStopped) {
    //TODO: fork ??
    pid_t pid;
    auto time=this->schedule_time.now();
    int job_id = this->jobs_list.size()+1;
    JobEntry new_job = JobEntry(cmd,pid,job_id,time,isStopped);
    this->jobs_list.assign(job_id,new_job);
}
std::string JobsList::JobEntry::print_job() {
    std::string res = "[" + to_string(job_id) + "]" + this->command->cmd_string() + " : " + to_string(this->pid);
    //TODO: add elapsed time!!
    return res;
}

void JobsList::printJobsList() {
    for (list<JobEntry>::iterator current = this->jobs_list.begin();current != this->jobs_list.end();current++){
        std::string res = current->print_job();
        cout<< res << "\n";
    }
}
void JobsList::killAllJobs() {
    for (list<JobEntry>::iterator  current = this->jobs_list.begin(); current!=this->jobs_list.end() ; current++) {
        JobEntry current_job = *current;
        this->jobs_list.erase(current);
        current_job.kill();
    }
}
JobsList::JobEntry * JobsList::getJobById(int jobId) {}

JobsList::JobEntry * JobsList::getLastJob(int *lastJobId) {}

void JobsList::removeFinishedJobs() {}

void JobsList::removeStoppedSign(int jobId) {
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++){
        if (current->job_id == jobId){
            JobEntry current_upt = *current;
            this->jobs_list.erase(current);
            current_upt.stopped= false;
            this->jobs_list.insert(current,current_upt);
        }
    }
}

JobsList::JobEntry* JobsList::getLastStoppedJob(int *jobId) {
    int max_id = this->jobs_list.begin()->job_id;
    JobEntry *last_stopped;
    for(list<JobEntry>::iterator current = this->jobs_list.begin(); current != this->jobs_list.end() ; current++) {
        if(current->job_id > max_id && current->stopped == true){
            max_id = current->job_id;
            *last_stopped = *current;
        }
    }
    *jobId = max_id;
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

string _ltrim(const std::string& s)
{
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

string _rtrim(const std::string& s)
{
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string _trim(const std::string& s)
{
  return _rtrim(_ltrim(s));
}

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

bool _isBackgroundComamnd(const char* cmd_line) {
  const string str(cmd_line);
  return str[str.find_last_not_of(WHITESPACE)] == '&';
}

void _removeBackgroundSign(char* cmd_line) {
  const string str(cmd_line);
  // find last character other than spaces
  unsigned int idx = str.find_last_not_of(WHITESPACE);
  // if all characters are spaces then return
  if (idx == string::npos) {
    return;
  }
  // if the command line does not end with & then return
  if (cmd_line[idx] != '&') {
    return;
  }
  // replace the & (background sign) with space and then remove all tailing spaces.
  cmd_line[idx] = ' ';
  // truncate the command line string up to the last non-space character
  cmd_line[str.find_last_not_of(WHITESPACE, idx) + 1] = 0;
}

// TODO: Add your implementation for classes in Commands.h 

SmallShell::SmallShell() {
// TODO: add your implementation
}

SmallShell::~SmallShell() {
// TODO: add your implementation
}

/**
* Creates and returns a pointer to Command class which matches the given command line (cmd_line)
*/
Command * SmallShell::CreateCommand(const char* cmd_line) {

  string cmd_s = string(cmd_line);
  if (cmd_s.find("pwd") == 0) {
    return new GetCurrDirCommand(cmd_line);
  }
  else if (cmd_s.find("chprompt") == 0){
    //todo: handle chrompt
  }
  else if (cmd_s.find("showpid") == 0){
    return new ShowPidCommand(cmd_line);
  }
  else if (cmd_s.find("cd") == 0){
    //todo: hanle the path that needs to be send to the c'tor
    //return new ChangeDirCommand(cmd_line,);
  }
  else if (cmd_s.find("jobs") == 0){
    //return new JobsCommand(cmd_line);
  }
  else if (cmd_s.find("kill") == 0){
     ///return new KillCommand(cmd_line);
  }
  else if (cmd_s.find("fg") == 0){
    //todo: FG command
  }
  else if (cmd_s.find("bg") == 0){
    //todo: BG command
  }
  else if (cmd_s.find("quit") == 0){
    //todo: QUIT command
  }
  else if (cmd_s.find(">") >= 0){
   // return new RedirectionCommand(cmd_line);
  }
  else if (cmd_s.find("|&") >= 0){
      //todo: handle |&
  }
  else if (cmd_s.find("|") >= 0){
      //todo: handle |
  }
  else {
    return new ExternalCommand(cmd_line);
  }


  return nullptr;
}

void SmallShell::executeCommand(const char *cmd_line) {
  // Todo: add to Jobs list if Background process
  // for example:
  // Command* cmd = CreateCommand(cmd_line);
  // cmd->execute();
  // Please note that you must fork smash process for some commands (e.g., external commands....)
}


#ifndef SMASH_COMMANDS_CPP
#define SMASH_COMMANDS_CPP

#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include "Commands.h"

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

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

    FUNC_ENTRY()
    vector<string> args;//COMMAND_MAX_ARGS
    std::istringstream iss(_trim(cmd_line));
    for (std::string str; iss >> str;) {
        args.push_back(str);
    }
    return args;
    FUNC_EXIT()
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
int JobCompare::operator()(JobEntry je1,JobEntry je2){
    return (je1.job_id - je2.job_id) < 0;
}


void JobsCommand::execute() {
    this->myJobs->printJobsList();
}


SmallShell::SmallShell(): last_cmd(nullptr),fg_job(nullptr){
    this->jobs_list = new JobsList();

}

bool SmallShell::isJobInList(pid_t pid){
    return this->jobs_list->getJobByPID(pid)->getpid() == pid;
}

void SmallShell::addJobToListZ(JobEntry *je){
    je->setNewId(this->jobs_list->getTopJobId() +1);
    this->jobs_list->addJobZ(je);
}

SmallShell::~SmallShell() {
    delete jobs_list;
}

Command * SmallShell::CreateCommand(const char* cmd_line) {

  string cmd_s = string(cmd_line);
  if (cmd_s.find("pwd") == 0) {
    return new GetCurrDirCommand(cmd_line);
  }
  else if (cmd_s.find("chprompt") == 0){
    return new ChangePrompt(cmd_line);
  }
  else if (cmd_s.find("showpid") == 0){
    return new ShowPidCommand(cmd_line);
  }
  else if (cmd_s.find("cd") == 0){
    return new ChangeDirCommand(cmd_line);
  }
  else if (cmd_s.find("jobs") == 0){
    return new JobsCommand(cmd_line,this->jobs_list);
  }
  else if (cmd_s.find("kill") == 0){
     return new KillCommand(cmd_line,this->jobs_list);
  }
  else if (cmd_s.find("fg") == 0){
    return new ForegroundCommand(cmd_line,this->jobs_list);
  }
  else if (cmd_s.find("bg") == 0){
    return new BackgroundCommand(cmd_line,this->jobs_list);
  }
  else if (cmd_s.find("quit") == 0){
     return new QuitCommand(cmd_line,this->jobs_list);
  }
  else if (cmd_s.find(">") >= 0){
      return new RedirectionCommand(cmd_line);
  }
  else if (cmd_s.find("|") >= 0){
      return new PipeCommand(cmd_line);
  }
  else if (cmd_s.find("cp") == 0){
      return new CopyCommand(cmd_line);
  }
  else {
    return new ExternalCommand(cmd_line);
  }
  return nullptr;
}

void SmallShell::executeCommand(const char *cmd_line){
    this->jobs_list->removeFinishedJobs();
    this->last_cmd = cmd_line;
    std:string command (cmd_line);
    bool isBg = (command.find("&") != std::string::npos);
    bool isNotBg = (command.find("|&") != std::string::npos);
    Command* cmd = CreateCommand(cmd_line);
    if(isBg && !isNotBg){
        pid_t pid = doFork();
        if(pid == 0){//son
            cmd->execute();
        }
        else {
            this->jobs_list->addJob(cmd,pid,false);
        }
    }
    else{
        pid_t pid = doFork();
        if ( pid == 0){
            this->fg_job = new JobEntry(cmd,getpid(),-1,std::chrono::system_clock::now(),false);
            cmd->execute();
        }
        else {
            waitpid(pid,nullptr,0);
        }


    }
}

bool SmallShell::setJobAsStopped(int pid) {
    return this->jobs_list->stopJobByPID(pid);

}
void SmallShell::killProcess(int pid) {
    this->jobs_list->killJob(pid);
}

void SmallShell::addCmd(Command *cmd,int pid){
    this->jobs_list->addJob(cmd,pid,true);
}

int SmallShell::getTopJobId() {
    return this->jobs_list->getTopJobId();
}

void SmallShell::setCurrentJobId(int newJobid){
    this->fg_job->setNewId(newJobid);
}

#endif




//
// Created by student on 4/22/20.
//
#include "exception"
#include <string>
#include <string.h>

#ifndef SMASH_MYEXCEPTIONS_H
#define SMASH_MYEXCEPTIONS_H


class MyException : public std::exception{
protected:
    std::string _msg;
public:

    MyException(): _msg("smash error: ") {};
     MyException(const char* syscall): _msg("smash error: "){
         //as instructed in the error handling part,
         // this is for a generic system call that fails
        this->_msg.append(syscall).append(" failed");
    }
    MyException(const char* syscall,const char* syscall_e_msg): _msg("smash error: "){
        this->_msg.append(syscall).append(" failed:").append(syscall_e_msg); //add the syscall's error msg
    }

    virtual const char* what()  noexcept  {
         return this->_msg.c_str();
     }
};

class MyCdException : public MyException { //handles Change Dir commands errors
    std::string _cdMsg;
public:
    MyCdException(): _cdMsg("cd: "){}
    MyCdException(char* errMsg): _cdMsg("cd: "){
       this->_cdMsg.append(errMsg); //should append the different cd errors to the origin
    }
    MyCdException(std::string errMsg): _cdMsg("cd: "){
        this->_cdMsg.append(errMsg); //should append the different cd errors to the origin
    }
    virtual const char * what() noexcept override{
        this->_msg.append(this->_cdMsg); //append the CD part to the generic part
        return this->_msg.c_str(); //return everything together
    }
};


//This exception is for the built in KillCommand:
class MyKillCommandException : public MyException {
    std::string _killMsg;
public:
    MyKillCommandException():_killMsg("kill: "){}
    MyKillCommandException(char* errMsg):_killMsg("kill: "){
        this->_msg.append(this->_killMsg.append(errMsg));
        ; //should append the different cd errors to the origin
    }
    MyKillCommandException(std::string errMsg):_killMsg("kill: "){
        this->_killMsg.append(errMsg); //should append the different cd errors to the origin
    }
    MyKillCommandException(int job_id):_killMsg("kill: "){
        std::string tmp = "job-id ";
        tmp.append(std::to_string(job_id));
        tmp = tmp + " does not exist";
        this->_killMsg.append(tmp); //appends the correct error message that needed to be split to half
    }

    virtual const char * what() noexcept override{
        return this->_killMsg.c_str();
    }
};

class MyFgException: public MyException { //handles Change Dir commands errors
    std::string _fgMsg;
public:
    MyFgException(): _fgMsg("fg: "){}
    MyFgException(char* errMsg): _fgMsg("fg: "){
        this->_fgMsg.append(errMsg); //should append the different cd errors to the origin
    }
    MyFgException(std::string errMsg): _fgMsg("fg: "){
        this->_fgMsg.append(errMsg); //should append the different cd errors to the origin
    }
    MyFgException(int job_id):_fgMsg("fg: "){
        std::string tmp = "job-id " + std::to_string(job_id);
        this->_fgMsg.append(tmp);
        tmp = " does not exist";
        this->_fgMsg.append(tmp); //appends the correct error message that needed to be split to half
    }
    virtual const char * what() noexcept override{
        this->_msg.append(this->_fgMsg); //append the CD part to the generic part
        return this->_msg.c_str(); //return everything together
    }
};


class MyBgException: public MyException { //handles Change Dir commands errors
    std::string _bgMsg;
public:
    MyBgException(): _bgMsg("bg: "){}
    MyBgException(char* errMsg): _bgMsg("bg: "){
        this->_bgMsg.append(errMsg); //should append the different cd errors to the origin
    }
    MyBgException(std::string errMsg): _bgMsg("bg: "){
        this->_bgMsg.append(errMsg); //should append the different cd errors to the origin
    }
    MyBgException(int job_id,std::string msg):_bgMsg("bg: "){
        std::string tmp = "job-id " + std::to_string( job_id) + " ";
        this->_bgMsg.append(tmp);
        this->_bgMsg.append(msg);
    }
    virtual const char * what() noexcept override{
        this->_msg.append(this->_bgMsg); //append the CD part to the generic part
        return this->_msg.c_str(); //return everything together
    }
};


//using MyException together with doPerror will print most of the needed error to the screen as they should be
//some edge exceptions still need to be addressed


class MySystemCallException : public std::exception{
    std::string _msg;
public:
    MySystemCallException(): _msg("smash error: ") {};
    MySystemCallException(const char* syscall): _msg("smash error: "){
        //as instructed in the error handling part,
        // this is for a generic system call that fails
        this->_msg.append(syscall).append(" failed");
    }
    MySystemCallException(const char* syscall,const char* syscall_e_msg): _msg("smash error: "){
        this->_msg.append(syscall).append(" failed:").append(syscall_e_msg); //add the syscall's error msg
    }
    virtual const char* what()  noexcept  {
        return this->_msg.c_str();
    }
};





/*
class MyNoArgsException : public std::exception{
public:
    virtual const char* what() const noexcept { return "smash error: no args provided";}
};


class MyOldPWDNotSetException : public std::exception{
public:
    virtual const char* what() const noexcept { return "smash error: cd: OLDPWD not set";}
};

*/

class MySpecialCommandException : public MyException{
public:
    MySpecialCommandException (){this->_msg.append("failed");};
    MySpecialCommandException (const char* msg) : MyException(msg) {this->_msg.append("failed");} //appends the failed to the rest of the message
    virtual const char* what() const noexcept { return this->_msg.c_str();}
};








#endif //SMASH_MYEXCEPTIONS_H

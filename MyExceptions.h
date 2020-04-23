//
// Created by student on 4/22/20.
//
#include "exception"

#ifndef SMASH_MYEXCEPTIONS_H
#define SMASH_MYEXCEPTIONS_H


class MyException : public std::exception{
public:
    std::string err_msg;
    MyException();
    MyException(const char* msg): exception(){
        err_msg.append(msg);
    }
    virtual const char* what() const noexcept  {return this->err_msg.c_str();}
};
//using MyException together with doPerror will print most of the needed error to the screen as they should be
//some edge exceptions still need to be addressed

/*
class MyTooManyArgsException : public std::exception{
public:
    virtual const char* what() const noexcept  { return "smash error: cd: too many arguments";}
};

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
    MySpecialCommandException (){this->err_msg.append("failed");};
    MySpecialCommandException (const char* msg) : MyException(msg) {this->err_msg.append("failed");} //appends the failed to the rest of the message
    virtual const char* what() const noexcept { return this->err_msg.c_str();}
};








#endif //SMASH_MYEXCEPTIONS_H

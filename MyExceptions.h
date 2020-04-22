//
// Created by student on 4/22/20.
//
#include "exception"

#ifndef SMASH_MYEXCEPTIONS_H
#define SMASH_MYEXCEPTIONS_H
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








#endif //SMASH_MYEXCEPTIONS_H

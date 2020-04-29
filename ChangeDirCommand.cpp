//
// Created by student on 4/22/20.
//
#include "Commands.h"
#include "MyExceptions.h"

//plastPwd = a vec<string> consists of all the parameters passed to the "cd" command
ChangeDirCommand::ChangeDirCommand(const char *cmd_line, char** plastPwd):BuiltInCommand(cmd_line){

    int count_params = -1; //ignore the first which is not a param

    char** cpy_plastPwd = plastPwd; //to keep the origin normal while iterating the params
    while(*cpy_plastPwd){
        char* cur_param = *cpy_plastPwd;
        this->params.push_back(cur_param);
        count_params++;
        cpy_plastPwd++;
    }
    this->num_params = count_params; //if this is bigger than 1 an exception will be thrown in execute.

}
void ChangeDirCommand::execute() {

    //get the current pwd (saving that later)
    char* pwd_buf = nullptr;
    ::getcwd(pwd_buf,0);//puts in pwd_buf the current working directory

    if (num_params > 1)
        throw MyCdException("too many arguments");

    else if(this->params[0].compare("-")==0){
       if(prev_pwd.empty())
           MyCdException("OLDPWD not set");
       try{
           ::chdir(prev_pwd.c_str());
       }
       catch (std::exception& e) {
           throw MyException("cd");
       }
       prev_pwd = pwd_buf;
    }


    try{
        if(this->params[0].compare("..")==0){
            std::string tmp (pwd_buf);
            int count_dash = 0;
            int i = 0;
            int last_dash = 0;
            while(*pwd_buf){
                if(*pwd_buf == '/'){
                    count_dash++;
                    last_dash = i;
                }
                pwd_buf++;
                i++;
            }
            if(last_dash-1 != 0){ //if it's not already in the top
                tmp = tmp.substr(0,last_dash-1);
                ::chdir(tmp.c_str());
            }

        }

        else if(this->params[0].compare(0,1,"/",0,1)==0){//check if it's a full path
            ::chdir(this->params[0].c_str()); //parsing the string to char*
            prev_pwd = pwd_buf;
        }
        else{
            //relative
            char* path;
            strcpy(pwd_buf,path);
            strcat(path,this->params[0].c_str()); //add relative to current dir
            ::chdir(path);
            prev_pwd = pwd_buf;
            free(path); //hopefully won't throw an error
        }
        free(pwd_buf);
    }
    catch (std::exception& e) {
        throw MyException("cd");
    }
}




/*
ChangeDirCommand::~ChangeDirCommand() noexcept {
    // Vector params & String prev_pwd call their dtor when needed
}
*/
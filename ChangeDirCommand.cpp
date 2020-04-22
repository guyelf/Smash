//
// Created by student on 4/22/20.
//
#include "Commands.h"
#include ""
char* ChangeDirCommand::prev_pwd = nullptr; //init for prev

//plastPwd = a vec<string> consists of all the parameters passed to the "cd" command
ChangeDirCommand::ChangeDirCommand(const char *cmd_line, char** plastPwd):BuiltInCommand(cmd_line){

    int count_params = 0;
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

    if (num_params != 1){
        if(num_params > 1){
            //Todo: throw Exception --> smash error: cd: too many arguments
        }
        else{
            //todo: throw Exception no-args exception - ?? necessary ?? - not mentioned
        }
    }
    if (this->params[0] == "-"){
        if (prev_pwd == nullptr){
            //todo: throw Exception --> smash error: cd: OLDPWD not set
        }
        ::chdir(prev_pwd); //changes the working dir to the previous one
         prev_pwd = pwd_buf;  //sets prev accordingly
    }
    else{ //regular chdir
        if(this->params[0].compare(0,1,"/",0,1)==0)
        {//in case it's a full path
            const char* dir_to_change = this->params[0];
            ::chdir(dir_to_change);
            prev_pwd = pwd_buf;
        }
    }

}


ChangeDirCommand::~ChangeDirCommand() noexcept {
    //todo: de-alloc the prev_pwd array
    //todo: de-alloc the vector
}

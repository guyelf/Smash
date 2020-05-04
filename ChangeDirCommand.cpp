//
// Created by student on 4/22/20.
//
#include "Commands.h"
#include "MyExceptions.h"

//plastPwd = a vec<string> consists of all the parameters passed to the "cd" command
/*
ChangeDirCommand::ChangeDirCommand(const char *cmd_line):BuiltInCommand(cmd_line){
  ///todo: maybe remove this c'tor
    int count_params = -1; //ignore the first which is not a param
    auto args = _parseCommandLineStrings(cmd_line);
    this->params = args;

    char** cpy_plastPwd = plastPwd; //to keep the origin normal while iterating the params
    while(*cpy_plastPwd){
        char* cur_param = *cpy_plastPwd;
        this->params.push_back(cur_param);
        count_params++;
        cpy_plastPwd++;
    }

    this->num_params = args.size() - 1; //if this is bigger than 1 an exception will be thrown in execute.

}
*/
ChangeDirCommand::ChangeDirCommand(const char *cmd_line):BuiltInCommand(cmd_line){
    auto args = _parseCommandLineStrings(cmd_line);
    this->params = args;
    this->num_params = args.size() - 1; //if this is bigger than 1 an exception will be thrown in execute.
}
std::string ChangeDirCommand::prev_pwd = "";

void ChangeDirCommand::execute() {

    //get the current pwd (saving that later)
    char* pwd_buf = nullptr;
    //::getcwd(pwd_buf,0);//puts in pwd_buf the current working directory
    pwd_buf = ::getcwd(pwd_buf,0);
    if (num_params > 1)
        throw MyCdException("too many arguments");

    else if(this->params[1].compare("-")==0){
       if(prev_pwd.empty())
           throw MyCdException("OLDPWD not set");
       try{
           ::chdir(prev_pwd.c_str());
       }
       catch (std::exception& e) {
           throw MyException("cd");
       }
       prev_pwd = pwd_buf;
    }



    else if(this->params[1].compare("..")==0){
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
        prev_pwd = tmp;
        if(last_dash-1 > 0 || tmp.size() > 1){ //if it's not already in the top
            tmp = tmp.substr(0,last_dash);
            ::chdir(tmp.c_str());
            if (last_dash == 0){
                ::chdir("/");
            }
        }
    }

    else if(this->params[1].compare(0,1,"/",0,1)==0){//check if it's a full path
        int res = ::chdir(this->params[1].c_str()); //parsing the string to char*
        if ( res == -1){
            throw MyException("chdir");
        }
        prev_pwd = pwd_buf;
    }
    else{
        //relative
        char* path = (char*)malloc(sizeof(char)*sizeof(pwd_buf));


        strcpy(pwd_buf,path);
        strcat(path,this->params[1].c_str()); //add relative to current dir
        int res =::chdir(path);
        if ( res == -1){
            throw MyException("chdir");
        }
        char * checkchekc = nullptr;
        checkchekc = ::getcwd(checkchekc,0);
        prev_pwd = pwd_buf;
        free(path); //hopefully won't throw an error
    }
    //free(pwd_buf);
}



/*
ChangeDirCommand::~ChangeDirCommand() noexcept {
    // Vector params & String prev_pwd call their dtor when needed
}
*/
//
// Created by student on 5/2/20.
//

#include "Commands.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 4096
using namespace std;

CopyCommand::CopyCommand(const char *cmd_line):Command(cmd_line),cmd_line(cmd_line){}

void CopyCommand::execute() {
    std::vector<string> args = _parseCommandLineStrings(cmd_line.c_str());

    if (args[1].compare(args[2].c_str()) == 0){// in case it's the same file
        if (open(args[1].c_str(),O_RDONLY,0666) != -1) { //and checking if it exists
            cout << "smash: " << args[1] << " was copied to " << args[2] << endl;
            return;
        }
        throw MyException("open");
    }
    int pid = doFork();

    char* buff = (char *) malloc(BUFF_SIZE);
    if(!buff)
        throw MyException("malloc");

    if (pid == 0){
        doClose(1);
        doClose(0);
        int files[2];
        int count_bytes;
        files[0] = open(args[1].c_str(),O_RDONLY,0666);
        if (files[0] == -1){ //Checking if file open
            MyException("open");
        }
        files[1] = open(args[2].c_str(),O_WRONLY|O_CREAT|O_TRUNC,0666);
        if (files[1] == -1){ //Checking if file open
            MyException("open");
        }

        count_bytes =  read(files[0],buff,BUFF_SIZE);
        while (count_bytes != 0){ //On reading the number of bytes read is returned, 0 if we reached EOF
            if(write(files[1],buff,count_bytes) == -1) //On writing -1 is returned if failed
               throw MyException("write");

            count_bytes =  read(files[0],buff,BUFF_SIZE);
        }

        doClose(files[0]);
        doClose(files[1]);
        exit(0); //otherwise the son goes to the smash and fucks up everything
    }
    else {
        waitpid(pid,nullptr, WUNTRACED);
        free(buff);
        cout << "smash: " << args[1] << " was copied to " << args[2] << endl;
    }
}
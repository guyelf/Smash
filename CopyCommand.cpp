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
    if (args[1].compare(args[2].c_str())){
        if (open(args[1].c_str(),O_RDONLY,0666) != -1) {
            cout << "smash: " + args[1] + " was copied to " + args[1] << endl;
        }
        return;
    }
    int pid = doFork();
    if ( pid == 0){
        char buff[BUFF_SIZE];
        close(1);
        close(0);
        int files[2];
        int count_bytes;
        files[0] = open(args[1].c_str(),O_RDONLY,0666);
        if (files[0] == -1){ //Checking if file open
            close(files[0]);
            //TODO:Exception??
        }
        files[1] = open(args[2].c_str(),O_WRONLY|O_CREAT|O_TRUNC,0666);
        if (files[1] == -1){ //Checking if file open
            close(files[1]);
            //TODO:Exception??
        }
        while (count_bytes = read(files[0],buff,BUFF_SIZE) != 0){ //On reading the number of bytes read is returned, 0 if we reached EOF
            write(files[1],buff,count_bytes);
        }
        //On writing -1 is returned if failed
    }
    else {
        wait(nullptr);
        cout << "smash: " + args[1] + " was copied to " + args[2] << endl;
    }
}
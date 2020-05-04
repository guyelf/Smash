#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <iterator>
#include <sstream>
#include <fstream>
#include "Commands.h"
#include "signals.h"

#define MAX_STRING_INPUT_SIZE 1600


int main(int argc, char* argv[]) {
    if(signal(SIGTSTP , ctrlZHandler)==SIG_ERR) {
        perror("smash error: failed to set ctrl-Z handler");
    }
    if(signal(SIGINT , ctrlCHandler)==SIG_ERR) {
        perror("smash error: failed to set ctrl-C handler");
    }

    //TODO: setup sig alarm handler
    SmallShell& smash = SmallShell::getInstance();
 /*   ifstream in_fli("/home/student/CLionProjects/Smash/kill_errors.in");
    char* cmd_line = (char*)malloc(MAX_STRING_INPUT_SIZE*sizeof(char));

    //char buffer[MAX_STRING_INPUT_SIZE];"/home/student/CLionProjects/Smash/test_input1.txt"
    //FILE* in_file;
    //in_file = fopen("/home/student/CLionProjects/Smash/test_input1.txt", "r");
    //while (fgets(buffer, MAX_STRING_INPUT_SIZE, in_file) != NULL) {
    //while (fgets(buffer, MAX_STRING_INPUT_SIZE, stdin) != NULL) {
    while(in_fli.getline(cmd_line,MAX_STRING_INPUT_SIZE)){
        try {
            std::cout << smash.prompt_name << endl;

            //getline(in_file, cmd_line);
            //std::getline(std::cin, cmd_line);
            smash.executeCommand(cmd_line);
        }
        catch (MyException& my) { //using the virtual method what to print to stdErr
            perror(my.what());
        }

    };

    return 0;
*/


    //set detach-on-fork off
    //set follow-fork-mode child
    while(true) {

        try {
            std::cout << smash.prompt_name <<ends;
            std::string cmd_line;
            std::getline(std::cin, cmd_line);
            smash.executeCommand(cmd_line.c_str());
        }
        catch (MyException& my) { //using the virtual method what to print to stdErr
            perror(my.what());
        }
    }
    return 0;

}// cp txt1.txt txt2.txt
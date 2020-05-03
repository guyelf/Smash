#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <iterator>
#include <sstream>
#include "Commands.h"
#include "signals.h"

int main(int argc, char* argv[]) {
    if(signal(SIGTSTP , ctrlZHandler)==SIG_ERR) {
        perror("smash error: failed to set ctrl-Z handler");
    }
    if(signal(SIGINT , ctrlCHandler)==SIG_ERR) {
        perror("smash error: failed to set ctrl-C handler");
    }

    //TODO: setup sig alarm handler
    std::string prompt_name = "smash> "; //default prompt
    SmallShell& smash = SmallShell::getInstance();
    while(true) {

        try {
            std::cout << prompt_name;
            std::string cmd_line;
            std::getline(std::cin, cmd_line);
            smash.executeCommand(cmd_line.c_str());


            //chprompt command:
            std::istringstream iss(cmd_line);
            std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                           std::istream_iterator<std::string>());
            if(words[0].compare("chprompt")==0){
                if(words.size() >= 1)
                    prompt_name = words[1]+"> "; //ignores the rest of the params if applied
                else
                    prompt_name = "smash> ";
            }
            //end chprompt
        }
        catch (MyException& my) { //using the virtual method what to print to stdErr
            perror(my.what());
        }
    }
    return 0;
}
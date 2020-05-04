//
// Created by student on 5/1/20.
//

#include "Commands.h"

ChangePrompt::ChangePrompt(const char *cmd_line): BuiltInCommand(cmd_line),cmd_line(cmd_line){}

ChangePrompt::~ChangePrompt() noexcept {}

void ChangePrompt::execute() {
    auto args = _parseCommandLineStrings(this->cmd_line.c_str());
    auto &smash = SmallShell::getInstance();
    if(args.size() == 1){ //the case where you go default
        smash.prompt_name = "smash> ";
    }
    else{
        string res = args[1].append("> ");
        smash.prompt_name = res;
    }
}


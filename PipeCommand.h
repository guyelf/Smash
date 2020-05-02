//
// Created by student on 4/23/20.
//

#ifndef SMASH_PIPECOMMAND_H
#define SMASH_PIPECOMMAND_H
#include "Commands.h"

class PipeCommand : public Command {
    std::string cmd_line;
public:
    explicit PipeCommand(const char* cmd_line);
    virtual ~PipeCommand();
    const char* cmd_string() override { return this->cmd_line.c_str();}
    void execute() override;
    void execute_pipe(std::vector<string> args);
    void execute_amp(std::vector<string> args);
};

#endif //SMASH_PIPECOMMAND_H

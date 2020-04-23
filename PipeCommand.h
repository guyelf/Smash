//
// Created by student on 4/23/20.
//

#ifndef SMASH_PIPECOMMAND_H
#define SMASH_PIPECOMMAND_H
#include "Commands.h"

class PipeCommand : public Command {
    // TODO: Add your data members
public:
    PipeCommand(const char* cmd_line);
    virtual ~PipeCommand() {}
    void execute() override;
};

#endif //SMASH_PIPECOMMAND_H

//
// Created by student on 4/23/20.
//
#include "Commands.h"
#ifndef SMASH_REDIRECTIONCOMMAND_H
#define SMASH_REDIRECTIONCOMMAND_H

enum RedirectionType {ONE_REDIRECTION, TWO_REDIRECTIONS};

class RedirectionCommand : public Command {
    RedirectionType r_type;
    int sign_index;
    std::string cmd;
public:
    explicit RedirectionCommand(const char* cmd_line);
    virtual ~RedirectionCommand() {}
    void execute() override;

    //void prepare() override;
    //void cleanup() override;
};


#endif //SMASH_REDIRECTIONCOMMAND_H

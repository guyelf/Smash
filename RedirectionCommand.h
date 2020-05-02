//
// Created by student on 4/23/20.
//

#ifndef SMASH_REDIRECTIONCOMMAND_H
#define SMASH_REDIRECTIONCOMMAND_H
#include "Commands.h"

enum RedirectionType {ONE_REDIRECTION, TWO_REDIRECTIONS};

class RedirectionCommand : public Command {
    RedirectionType r_type;
    int sign_index;
    std::string current_cmd;
public:
    explicit RedirectionCommand(const char* cmd_line);
    virtual ~RedirectionCommand() {}
    void execute() override;
    const char* cmd_string() override { return this->cmd.c_str();}
    //void prepare() override;
    //void cleanup() override;
};


#endif //SMASH_REDIRECTIONCOMMAND_H

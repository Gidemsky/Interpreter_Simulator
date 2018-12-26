//
// Created by benda on 26/12/18.
//

#ifndef SIMULATOR_CMDTEST_H
#define SIMULATOR_CMDTEST_H

#include "Command.h"
#include "Data.h"
#include "CommandExpression.h"

class CmdTest : public Command {
    Data* d;
    vector<CommandExpression*> cmds;
    string cond;

public:
    CmdTest(vector<CommandExpression*> cmds, string cond, Data* d);
    virtual double execute();
};


#endif //SIMULATOR_CMDTEST_H

//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_COMMANDEXPRESSION_H
#define SIMULATOR_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"


class CommandExpression : public Expression {
    Command* cmd;
public:
    CommandExpression(Command* cmd);
    double calculate();
    Command* getCommand();
};


#endif //SIMULATOR_COMMANDEXPRESSION_H

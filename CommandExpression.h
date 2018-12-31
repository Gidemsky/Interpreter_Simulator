
#ifndef SIMULATOR_COMMANDEXPRESSION_H
#define SIMULATOR_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
    Command* cmd;

public:
    CommandExpression(Command* cmd);
    double calculate();
};


#endif //SIMULATOR_COMMANDEXPRESSION_H

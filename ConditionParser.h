
#ifndef SIMULATOR_CONDITIONPARSER_H
#define SIMULATOR_CONDITIONPARSER_H

#include <vector>
#include "Command.h"
#include "CommandExpression.h"
#include "string"

class ConditionParser : public Command {
public:
    vector<CommandExpression*> commands;
    string condition;

    ConditionParser(
            vector<CommandExpression*> commands, string condition );
    virtual double execute();
};

#endif //SIMULATOR_CONDITIONPARSER_H

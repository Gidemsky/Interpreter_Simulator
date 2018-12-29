
#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

#include "ConditionParser.h"
#include "CommandExpression.h"
#include "Data.h"
#include "Condition.h"

extern Data data;

class LoopCommand : public ConditionParser {
public:
    LoopCommand(vector<CommandExpression*> commands,
            string condition);
    virtual double execute();
};

#endif //SIMULATOR_LOOPCOMMAND_H

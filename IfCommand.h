
#ifndef SIMULATOR_IFCOMMAND_H
#define SIMULATOR_IFCOMMAND_H

#include "ConditionParser.h"
#include "CommandExpression.h"
#include "Expression.h"
#include "string"
#include "Condition.h"
#include "Data.h"

extern Data data;

class IfCommand : public ConditionParser {
public:
    IfCommand(vector<CommandExpression*> commands,
            string condition);
    virtual double execute();
};

#endif //SIMULATOR_IFCOMMAND_H

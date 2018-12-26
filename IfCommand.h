//
// Created by benda on 23/12/18.
//

#ifndef SIMULATOR_IFCOMMAND_H
#define SIMULATOR_IFCOMMAND_H

#include "ConditionParser.h"
#include "CommandExpression.h"
#include "Expression.h"
#include "string"
#include "Condition.h"
///
class IfCommand : public ConditionParser {

public:
    // ctor
    IfCommand(vector<CommandExpression*> commands,
            string condition);
    // methods
    virtual double execute();
};

#endif //SIMULATOR_IFCOMMAND_H

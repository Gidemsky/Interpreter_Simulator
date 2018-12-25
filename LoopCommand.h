//
// Created by benda on 23/12/18.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

//
#include "ConditionParser.h"
#include "CommandExpression.h"
#include "Data.h"
#include "Condition.h"

class LoopCommand : public ConditionParser {
    // members
    Data* data;

public:
    // ctor
    LoopCommand(vector<CommandExpression*> commands,
            string condition, Data* data);
    // methods
    virtual double execute();
};

#endif //SIMULATOR_LOOPCOMMAND_H

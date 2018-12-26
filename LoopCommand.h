//
// Created by benda on 23/12/18.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

///
#include "ConditionParser.h"
#include "CommandExpression.h"
#include "Data.h"
#include "Condition.h"
extern Data data;
class LoopCommand : public ConditionParser {
    // members


public:
    // ctor
    LoopCommand(
            vector<CommandExpression*> commands, string condition);
    // methods
    virtual double execute();
};

#endif //SIMULATOR_LOOPCOMMAND_H

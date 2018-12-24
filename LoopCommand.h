//
// Created by benda on 23/12/18.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H


#include "ConditionParser.h"
#include "IfCommand.h"

class LoopCommand : public ConditionParser {
    // members
    IfCommand if_cmd;

public:
    // methods
    virtual double execute();
};


#endif //SIMULATOR_LOOPCOMMAND_H

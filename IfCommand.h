//
// Created by benda on 23/12/18.
//

#ifndef SIMULATOR_IFCOMMAND_H
#define SIMULATOR_IFCOMMAND_H

#include "ConditionParser.h"
#include "Expression.h"
#include "string"

class IfCommand : public ConditionParser {
public:
    // ctor
    IfCommand(list<Command*> commands, string condition);
    // methods
    virtual double execute();
};


#endif //SIMULATOR_IFCOMMAND_H

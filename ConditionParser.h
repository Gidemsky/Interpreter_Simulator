//
// Created by benda on 23/12/18.
//

#ifndef SIMULATOR_CONDITIONPARSER_H
#define SIMULATOR_CONDITIONPARSER_H

#include "Command.h"
#include "list"
#include "string"

class ConditionParser : public Command {
public:
    // members
    list<Command*> commands;
    string condition;

    // ctor
    ConditionParser(list<Command*> commands,
            string condition);

    // methods
    virtual double execute();
};

#endif //SIMULATOR_CONDITIONPARSER_H

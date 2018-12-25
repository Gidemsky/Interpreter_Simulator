//
// Created by benda on 23/12/18.
//

#include "LoopCommand.h"

//
LoopCommand::LoopCommand(
        list <CommandExpression*> commands,
        string condition, Data* data) :
        ConditionParser(commands, condition) {
    this->data = data;
}

double LoopCommand::execute() {
    Condition* cond = new Condition(this->condition, data);
    while (cond->evaluate()) {
        ConditionParser::execute();
    }
}
//
// Created by benda on 23/12/18.
//

#include "LoopCommand.h"

/////
LoopCommand::LoopCommand(vector <CommandExpression*> commands,
                         string condition) :
        ConditionParser(commands, condition) {
    //this->data = data;
}

double LoopCommand::execute() {
    Condition* cond = new Condition(this->condition);
    while (cond->evaluate()) {
        ConditionParser::execute();
    }
}
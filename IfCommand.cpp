//
// Created by benda on 23/12/18.
//

#include "IfCommand.h"
#include "Data.h"
extern Data data;
//
IfCommand::IfCommand(vector<CommandExpression*> commands,
        string condition):ConditionParser(
        commands, condition) {
   // this->data = data;
}

double IfCommand::execute() {
    Condition* cond = new Condition(
            this->condition);
    if (cond->evaluate()) {
        ConditionParser::execute();
    }
}
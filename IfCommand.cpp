//
// Created by benda on 23/12/18.
//

#include "IfCommand.h"
///
IfCommand::IfCommand(vector<CommandExpression*> commands,
        string condition, Data* data):ConditionParser(
        commands, condition) {
    this->data = data;
}

double IfCommand::execute() {
    Condition* cond = new Condition(
            this->condition, this->data);
    if (cond->evaluate()) {
        ConditionParser::execute();
    }
}
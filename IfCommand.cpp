
#include "IfCommand.h"

/**
 * Ctor.
 * @param commands
 * @param condition
 */
IfCommand::IfCommand(vector<CommandExpression*> commands,
        string condition):ConditionParser(
        commands, condition) {
}

/**
 * Execute all the command in the if scope.
 * @return
 */
double IfCommand::execute() {
    Condition* cond = new Condition(this->condition);
    if (cond->evaluate()) {
        ConditionParser::execute();
    }
}

#include "LoopCommand.h"

/**
 * Ctor.
 * @param commands
 * @param condition
 */
LoopCommand::LoopCommand(vector <CommandExpression*> commands,
                         string condition) :
        ConditionParser(commands, condition) {
}

/**
 * Execute all the commands in the while loop.
 * @return
 */
double LoopCommand::execute() {
    Condition* cond = new Condition(this->condition);
    while (cond->evaluate()) {
        ConditionParser::execute();
    }
}
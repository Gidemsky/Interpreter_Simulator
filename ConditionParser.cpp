
#include "ConditionParser.h"
#include "Expression.h"
#include "ShuntingYard.h"

/**
 * Ctor.
 * @param commands
 * @param condition
 */
ConditionParser::ConditionParser(
        vector<CommandExpression*> commands, string condition) {
    this->commands = commands;
    this->condition = condition;
}

/**
 * Execute all the command expressions of the condition parser.
 * @return
 */
double ConditionParser::execute() {
    for (CommandExpression* cmd : this->commands) {
        cmd->calculate();
    }
}

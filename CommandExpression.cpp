
#include "CommandExpression.h"

/**
 * Ctor.
 * @param cmd
 */
CommandExpression::CommandExpression(Command* cmd) {
    this->cmd = cmd;
}

/**
 * Execute the command.
 * @return
 */
double CommandExpression::calculate() {
    cmd->execute();
    return 0;
}

/**
 * Getter of the command.
 * @return the command.
 */
Command* CommandExpression::getCommand() {
    return this->cmd;
}
//
// Created by gideon on 18/12/18.
//
//
#include "CommandExpression.h"

CommandExpression::CommandExpression(Command* cmd) {
    this->cmd = cmd;
}

double CommandExpression::calculate() {
    cmd->execute();
}

/**
 * Getter of the command.
 * @return the command.
 */
Command* CommandExpression::getCommand() {
    return this->cmd;
}
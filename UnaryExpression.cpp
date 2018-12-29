
#include "UnaryExpression.h"

/**
 * Constructor.
 * @param arg
 */
UnaryExpression::UnaryExpression(Expression* arg) {
    this->arg = arg;
}

/**
 * Getter of the argument
 * @return the left argument.
 */
Expression* UnaryExpression::getArg() {
    return this->arg;
}
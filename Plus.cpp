
#include "Plus.h"

/**
 * Constructor.
 */
Plus::Plus(Expression* left, Expression* right):
    BinaryExpression(left, right) {
}

/**
 * Calculate the result.
 * @return the result.
 */
double Plus::calculate() {
    return this->getLeftArg()->calculate() +
        this->getRightArg()->calculate();
}

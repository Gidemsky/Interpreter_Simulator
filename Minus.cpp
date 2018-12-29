
#include "Minus.h"

/**
 * Constructor.
 */
Minus::Minus(Expression* left, Expression* right):BinaryExpression(left, right) {
}

/**
 * Calculate the result.
 * @return the result.
 */
double Minus::calculate() {
    return this->getLeftArg()->calculate() -
           this->getRightArg()->calculate();
}

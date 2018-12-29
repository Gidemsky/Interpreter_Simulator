
#include "Mult.h"

/**
 * Constructor.
 */
Mult::Mult(Expression* left, Expression* right):BinaryExpression(left, right) {
}

/**
 * Calculate the result.
 * @return the result.
 */
double Mult::calculate() {
    return this->getLeftArg()->calculate() *
           this->getRightArg()->calculate();
}

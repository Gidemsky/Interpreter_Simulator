
#include "Neg.h"

/**
 * Constructor.
 */
Neg::Neg(Expression* arg):
        UnaryExpression(arg) {
}

/**
 * Calculate the result.
 * @return the result.
 */
double Neg::calculate() {
    return -(this->getArg()->calculate());
}
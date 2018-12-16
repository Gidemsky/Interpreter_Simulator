//
// Created by benda on 14/12/18.
//

#include "Plus.h"
#include "BinaryExpression.h"

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

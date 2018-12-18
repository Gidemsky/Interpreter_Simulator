//
// Created by benda on 14/12/18.
//

#include "BinaryExpression.h"

/**
 * Constructor.
 * @param left
 * @param right
 */
BinaryExpression::BinaryExpression(Expression* left, Expression* right) {
    this->left_arg = left;
    this->right_arg = right;
}

/**
 * Getter of the left argument.
 * @return the left argument.
 */
Expression* BinaryExpression::getLeftArg() {
    return this->left_arg;
}

/**
 * Getter of the right argument.
 * @return the right argument.
 */
Expression* BinaryExpression::getRightArg() {
    return this->right_arg;
}
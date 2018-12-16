//
// Created by benda on 17/12/18.
//

#ifndef SIMULATOR_MINUS_H
#define SIMULATOR_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right);
    virtual double calculate();
};


#endif //SIMULATOR_MINUS_H

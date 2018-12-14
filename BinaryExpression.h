//
// Created by benda on 14/12/18.
//

#ifndef SIMULATOR_BINARYEXPRESSION_H
#define SIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
    Expression first_exp;
    Expression second_exp;

public:
    virtual double calculate();
};

#endif //SIMULATOR_BINARYEXPRESSION_H

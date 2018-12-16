//
// Created by benda on 17/12/18.
//

#ifndef SIMULATOR_DIV_H
#define SIMULATOR_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //SIMULATOR_DIV_H

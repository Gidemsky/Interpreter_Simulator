//
// Created by benda on 17/12/18.
//

#ifndef SIMULATOR_NEG_H
#define SIMULATOR_NEG_H


#include "UnaryExpression.h"

class Neg : public UnaryExpression{
public:
    // constructor
    Neg(Expression* arg);
    virtual double calculate();
};


#endif //SIMULATOR_NEG_H

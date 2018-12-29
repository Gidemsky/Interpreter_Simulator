
#ifndef SIMULATOR_PLUS_H
#define SIMULATOR_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression* left, Expression* right);
    virtual double calculate();
};

#endif //SIMULATOR_PLUS_H

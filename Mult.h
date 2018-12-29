
#ifndef SIMULATOR_MULT_H
#define SIMULATOR_MULT_H

#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression* left, Expression* right);
    virtual double calculate();
};

#endif //SIMULATOR_MULT_H

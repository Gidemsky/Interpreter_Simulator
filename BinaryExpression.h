
#ifndef SIMULATOR_BINARYEXPRESSION_H
#define SIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* left_arg;
    Expression* right_arg;

public:
    BinaryExpression(Expression* left, Expression* right);
    virtual double calculate() = 0;
    virtual Expression* getLeftArg();
    virtual Expression* getRightArg();
};

#endif //SIMULATOR_BINARYEXPRESSION_H

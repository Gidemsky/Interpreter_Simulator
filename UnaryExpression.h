
#ifndef SIMULATOR_UNARYEXPRESSION_H
#define SIMULATOR_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression* arg;

public:
    UnaryExpression(Expression* arg);
    virtual double calculate() = 0;
    virtual Expression* getArg();
};


#endif //SIMULATOR_UNARYEXPRESSION_H

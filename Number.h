
#ifndef SIMULATOR_NUMBER_H
#define SIMULATOR_NUMBER_H

#include "Expression.h"
#include "string"

using namespace std;

class Number : public Expression {
    double num;

public:
    Number(double num);
    Number(string num);
    virtual double calculate();
    virtual void evaluateVar();
};

#endif //SIMULATOR_NUMBER_H


#ifndef SIMULATOR_NUMBER_H
#define SIMULATOR_NUMBER_H

#include "Expression.h"
#include "string"
#include "Data.h"

using namespace std;

extern Data data;

class Number : public Expression {
    double num;

public:
    Number(double num);
    Number(string num);
    virtual double calculate();
};

#endif //SIMULATOR_NUMBER_H

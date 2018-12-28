
#ifndef SIMULATOR_NUMBER_H
#define SIMULATOR_NUMBER_H

#include "Expression.h"
#include "string"
#include "Data.h"
#include <ctype.h>
using namespace std;

extern Data data;

class Number : public Expression {
    double num;

public:
    Number(string arg);
    bool isNumber(string arg);
    virtual double calculate();
};

#endif //SIMULATOR_NUMBER_H

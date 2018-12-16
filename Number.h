//
// Created by benda on 14/12/18.
//

#ifndef SIMULATOR_NUMBER_H
#define SIMULATOR_NUMBER_H

#include "Expression.h"

class Number : public Expression {
    double num;

public:
    // constructor
    Number(double num);
    virtual double calculate();

};


#endif //SIMULATOR_NUMBER_H

//
// Created by benda on 24/12/18.
//

#ifndef SIMULATOR_CONDITION_H
#define SIMULATOR_CONDITION_H

#include "string"
#include "Data.h"
#include "ShuntingYard.h"
extern Data data;
using namespace std;

class Condition {
    string condition;


public:
    Condition(string condition);
    int findOperatorIndex();
    string getOperatorStr(int index);
    bool evaluate();
};

#endif //SIMULATOR_CONDITION_H

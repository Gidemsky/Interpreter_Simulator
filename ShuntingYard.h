
#ifndef SIMULATOR_SHOUTINGYARD_H
#define SIMULATOR_SHOUTINGYARD_H

#include <map>
#include "Expression.h"
#include "stack"

using namespace std;

class ShuntingYard {
    map<char, int> op_dictionary = {{'(',0}, {')',0},
                                {'-',1}, {'+',1},
                                {'*',2}, {'/',2}
    };

public:
    ShuntingYard();
    void initializeMap();
    int precedence(char operation);
    Expression *createExpression(string tokens);
    Expression* applyOp(Expression* val1, Expression* val2, char operation);
};

#endif //SIMULATOR_SHOUTINGYARD_H

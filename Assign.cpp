
#include <iostream>
#include "Assign.h"
#include "ShuntingYard.h"

#define VAR_INDEX 0
#define VALUE_INDEX 2

/**
 * Ctor.
 * @param params include the var name and his value.
 */
Assign::Assign(vector<string> params){
    string arg;
    ShuntingYard sy;
    this->var = params[VAR_INDEX];
    for (int i = VALUE_INDEX; i < params.size(); i++) {
        arg += params[i];
    }
    // get the value using the shunting yard
    this->value = sy.createExpression(arg)->calculate();
}

/**
 *
 * @return
 */
double Assign::execute() {
    // add to the symbol table
    data.setSymbolTable(this->var, this->value);
    return 0;
}

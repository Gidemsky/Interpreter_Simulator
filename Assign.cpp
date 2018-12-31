
#include <iostream>
#include "Assign.h"
#include "ShuntingYard.h"

/**
 * Ctor.
 * @param var
 * @param value
 */
Assign::Assign(string var, string value) {
    this->var = var;
    this->value = value;
}

/**
 * Execute.
 * @return
 */
double Assign::execute() {
    ShuntingYard sy;
    data.setNewPlaneData(this->var,
            sy.createExpression(this->value)->calculate());
    return 0;
}

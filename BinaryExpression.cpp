//
// Created by benda on 14/12/18.
//

#include "BinaryExpression.h"

double BinaryExpression::calculate() {
    return this->first_exp->calculate() + this->second_exp->calculate();
}


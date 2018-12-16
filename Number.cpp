//
// Created by benda on 14/12/18.
//

#include "Number.h"

/**
 * Constructor.
 * @param num is the number.
 */
Number::Number(double num) {
    this->num = num;
}

/**
 * Calculate.
 * @return the number.
 */
double Number::calculate() {
    return this->num;
}
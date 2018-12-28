
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

/**
 * Constructor for the variable.
 * @param var is the variable.
 */
Number::Number(string var) {
    if(any_of(var.begin(),var.end(),isChar))
    map<string, double> symbol_table = data.getSymbolTable();
    std::map<string, double>::iterator it;
    // get the value of the variable
    it = symbol_table.find(var);
    if (it != symbol_table.end()) {
        this->num = it->second;
    }
}
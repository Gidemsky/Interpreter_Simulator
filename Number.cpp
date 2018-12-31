
#include "Number.h"

/**
 * Constructor.
 * @param arg
 */
Number::Number(string arg) {
    unsigned long pos;
    if ((pos = arg.find('.')) != string::npos) {
        string numerator = arg.substr(0, pos);
        if (isNumber(numerator)) {
            numerator = arg.substr(pos + 1, arg.npos);
            if (isNumber(numerator)) {
                this->num = stod(arg);
            }
        }
    } else if (this->isNumber(arg)) {
        this->num = stod(arg);
    } else {
        map<string, double> symbol_table = data.getSymbolTable();
        this->num = symbol_table.at(arg);
    }
}

/**
 * Check if the string is number or variable.
 * @param arg
 * @return true if it's a number, otherwise false.
 */
bool Number::isNumber(string arg) {
    for (int i = 0; i < arg.length(); i++) {
        if (isdigit(arg[i])) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

/**
 * Calculate.
 * @return the number.
 */
double Number::calculate() {
    return this->num;
}

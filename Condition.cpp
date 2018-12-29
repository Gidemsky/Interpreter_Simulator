
#include "Condition.h"
#include "iostream"
#include "algorithm"

#define OPERATORS {"<", ">", "=", "!"}

/**
 * Ctor.
 * @param condition
 */
Condition::Condition(string condition) {
    this->condition = condition;
}

/**
 * Find the index of the operator.
 * @return the index.
 */
int Condition::findOperatorIndex() {
    vector<string> operators OPERATORS;
    int index = -1;
    for (string opr : operators) {
        index = this->condition.find(opr);
        if (index != std::string::npos) {
            return index;
        }
    }
    if (index == -1) {
        throw "there is no operator in the condition";
    }
}

/**
 * Get the operator string.
 * @param index is the first index of the operator
 * in the condition string.
 * @return
 */
string Condition::getOperatorStr(int index) {
    string opr;
    if (this->condition.at(index + 1) == '=') {
        return this->condition.substr(index, 2);
    }
    opr = this->condition.at(index);
    return opr;
}

/**
 * Check the condition.
 * @param condition
 * @return true if the condition is satisfied, otherwise false.
 */
bool Condition::evaluate() {
    // using shunting yard in order to calculate the expressions.
    ShuntingYard sy;
    string::iterator end_pos = remove(this->condition.begin(),
                                      this->condition.end(), ' ');
    condition.erase(end_pos, condition.end());
    // get the index of the operator in the condition string
    int opr_index = this->findOperatorIndex();
    string opr = this->getOperatorStr(opr_index);
    string first_exp;
    string second_exp;
    first_exp = this->condition.substr(0, opr_index);
    // check the operator's type
    if (opr.length() == 1) {
        second_exp = this->condition.substr(
                opr_index + 1, this->condition.length() - 1);
    } else {
        second_exp = this->condition.substr(
                opr_index + 2, this->condition.length() - 1);
    }
    // calculate the expressions using the shunting yard
    Expression *left = sy.createExpression(first_exp);
    Expression *right = sy.createExpression(second_exp);
    double left_value = left->calculate();
    double right_value = right->calculate();

    /* check the condition */
    if (opr == "<") {
        return left_value < right_value;
    } else if (opr == ">") {
        return left_value > right_value;
    } else if (opr == "==") {
        return left_value == right_value;
    } else if (opr == ">=") {
        return left_value >= right_value;
    } else if (opr == "<=") {
        return left_value <= right_value;
    } else if (opr == "!=") {
        return left_value != right_value;
    }
}

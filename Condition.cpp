//
// Created by benda on 24/12/18.
//

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
    //this->data = data;
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
            cout << index << " index" << endl;
            return index;
        }
    }
    if (index == -1) {
        throw "there is no operator in the condition";
    }
}
//
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
    ShuntingYard *sy = new ShuntingYard();

    string::iterator end_pos = remove(this->condition.begin(),
            this->condition.end(), ' ');

    condition.erase(end_pos, condition.end());

    cout << this->condition << endl;

    vector<string> operators OPERATORS;
    // get the index of the operator
    int opr_index = this->findOperatorIndex();
    string opr = this->getOperatorStr(opr_index);
    cout << opr << " opr " << endl;
    string first_exp;
    string second_exp;

    first_exp = this->condition.substr(0, opr_index);

    if (opr.length() == 1) {
        second_exp = this->condition.substr(
                opr_index + 1, this->condition.length() - 1);
    } else {
        second_exp = this->condition.substr(
                opr_index + 2, this->condition.length() - 1);
    }

    cout << first_exp << endl;
    cout << second_exp << endl;

    Expression *left = sy->createExpression(first_exp);
    Expression *right = sy->createExpression(second_exp);

    double left_value = left->calculate();
    double right_value = right->calculate();

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
    } else {
        throw "unknown operator in the condition";
    }
}

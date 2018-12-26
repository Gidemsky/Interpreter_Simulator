//
// Created by benda on 23/12/18.
//

#include "ConditionParser.h"
#include "Expression.h"
#include "ShuntingYard.h"

/* save - old version
#define CONDITION_TYPE 0
#define LEGT_ARG 1
#define CONDITION_OPERATOR 2
#define RIGHT_ARG 3 */

////
ConditionParser::ConditionParser(
        vector<CommandExpression*> commands, string condition) {
    this->commands = commands;
    this->condition = condition;
}

double ConditionParser::execute() {
    for (CommandExpression* cmd : this->commands) {
        cmd->calculate();
    }
}

// save - old version
// /**
//  * Parse the condition string from the script, and check
//  * the condition.
//  * @return true if the condition is satisfied, otherwise false.
//  */
//bool ConditionParser::parse() {
//    ShuntingYard* sy = new ShuntingYard();
//    string opr = this->params[CONDITION_OPERATOR];
//    Expression* right = sy->createExpression(this->params[RIGHT_ARG]);
//    map<string, double>::iterator it;
//    // get the var's value
//    double left_value =
//            this->symbol_table.find(this->params[LEGT_ARG])->second;
//    double right_value = right->calculate();
//    if (opr == "<") {
//        return left_value < right_value;
//    } else if (opr == ">") {
//        return left_value > right_value;
//    } else if (opr == "==") {
//        return left_value == right_value;
//    } else if (opr == ">=") {
//        return left_value >= right_value;
//    } else if (opr == "<=") {
//        return left_value <= right_value;
//    } else if (opr == "!=") {
//        return left_value != right_value;
//    } else {
//        throw "unknown operator in the condition";
//    }
//
//    if (this->params[CONDITION_TYPE] == "while") {
//
//    } else if (this->params[CONDITION_TYPE] == "if") {
//
//    }
//
//
//}


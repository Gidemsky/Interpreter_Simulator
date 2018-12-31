
#include "ShuntingYard.h"
#include "Number.h"
#include "Mult.h"
#include "Div.h"
#include "Minus.h"
#include "Plus.h"

/**
 * Ctor.
 */
ShuntingYard::ShuntingYard() {
    initializeMap();
}

void ShuntingYard::initializeMap() {
}

/**
 *
 * @param operation
 * @return
 */
int ShuntingYard::precedence(char operation) {
    if (this->op_dictionary.count(operation)) {
        return this->op_dictionary.at(operation);
    }
    throw "invalid operation!";
}

/**
 * Aid function for the expression creation.
 * @param val1
 * @param val2
 * @param operation
 * @return the expression
 */
Expression *ShuntingYard::applyOp(Expression *val1, Expression *val2, char operation) {
    switch (operation) {
        case '*': {
            Mult* m = new Mult(val1, val2);
            data.addToDelete(m);
            return m;
        }
        case '/': {
            Div* d = new Div(val1, val2);
            data.addToDelete(d);
            return d;
        }
        case '+': {
            Plus* p = new Plus(val1, val2);
            data.addToDelete(p);
            return p;
        }
        case '-': {
            Minus* m = new Minus(val1, val2);
            data.addToDelete(m);
            return m;
        }
        default:
            break;
    }
}

/**
 * Create the expression
 * @param tokens
 * @return the expression
 */
Expression *ShuntingYard::createExpression(string tokens) {
    stack<Expression *> value;
    stack<char> operators;

    for (int i = 0; i < tokens.length(); i++) {
        // skip white space
        if (tokens[i] == ' ')
            continue;
        // push it to the operators stack
        else if (tokens[i] == '(') {
            operators.push(tokens[i]);
        }
        // push it to the values stack
        else if (isdigit(tokens[i]) || isalpha(tokens[i])) {
            string val;
            while ((i < tokens.length() &&
                    (isdigit(tokens[i]) || isalpha(tokens[i])))
                   || tokens[i] == '.') {
                val += tokens[i];
                i++;
            }
            i--;
            Expression *num = new Number(val);
            data.addToDelete(num);
            value.push(num);
        }
        // the closing brace
        else if (tokens[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                Expression *val2 = value.top();
                value.pop();
                Expression *val1 = value.top();
                value.pop();
                char op = operators.top();
                operators.pop();
                value.push(applyOp(val1, val2, op));
            }
            // pop opening brace.
            operators.pop();
        }
        // Current token is an operator.
        else {
            while (!operators.empty() && precedence(operators.top())
                                         >= precedence(tokens[i])) {
                Expression *val2 = value.top();
                value.pop();
                Expression *val1 = value.top();
                value.pop();
                char op = operators.top();
                operators.pop();
                value.push(applyOp(val1, val2, op));
            }
            // Push current token to 'ops'
            operators.push(tokens[i]);
        }
    }

    // apply all the remaining operators
    while (!operators.empty()) {
        Expression *val2 = value.top();
        value.pop();
        Expression *val1 = value.top();
        value.pop();
        char op = operators.top();
        operators.pop();
        value.push(applyOp(val1, val2, op));
    }
    return value.top();
}
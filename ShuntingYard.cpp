
#include "ShuntingYard.h"
#include "Number.h"
#include "Mult.h"
#include "Div.h"
#include "Minus.h"
#include "Plus.h"

ShuntingYard::ShuntingYard() {
    initializeMap();
}

void ShuntingYard::initializeMap() {
}

int ShuntingYard::precedence(char operation) {
    if (this->op_dictionary.count(operation)) {
        return this->op_dictionary.at(operation);
    }
    throw "invalid operation!";
}

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

// Function that returns value of
// expression after evaluation.
Expression *ShuntingYard::createExpression(string tokens) {
    //int i;
    // stack to store integer values.
    stack<Expression *> value;
    // stack to store operators.
    stack<char> operators;
    for (int i = 0; i < tokens.length(); i++) {
        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;
            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            operators.push(tokens[i]);
        }
            // Current token is a number, push
            // it to stack for numbers.
        else if (isdigit(tokens[i]) || isalpha(tokens[i])) {
            string val;
            // There may be more than one
            // digits in number.
            while ((i < tokens.length() &&
                    (isdigit(tokens[i]) || isalpha(tokens[i])))
                   || tokens[i] == '.') {
                //val = (val * 10) + (tokens[i] - '0');
                val += tokens[i];
                i++;
            }
            i--;
            //double converted_number = stod(val);
            Expression *num = new Number(val);
            data.addToDelete(num);
            value.push(num);
        }
            // Closing brace encountered, solve
            // entire brace.
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
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
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
            // Push current token to 'ops'.
            operators.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!operators.empty()) {
        Expression *val2 = value.top();
        value.pop();
        Expression *val1 = value.top();
        value.pop();
        char op = operators.top();
        operators.pop();
        value.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return value.top();
}
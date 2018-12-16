#include <iostream>

#include "Interpreter.h"
#include "Expression.h"
#include "Plus.h"
#include "Number.h"
#include "Div.h"
#include "Mult.h"
#include "Minus.h"
int main() {
    std::cout << "DBD LEGEND" << std::endl;
    //Interpreter* check = new Interpreter("CommandTestFile.txt");
    Expression* exp = new Minus(new Plus(new Number(3.0), new Number(7.0)),
            new Number(5.0));
    std::cout << exp->calculate() << std::endl;
    return 0;
}
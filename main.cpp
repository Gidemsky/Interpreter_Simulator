#include <iostream>

#include "Interpreter.h"
#include "Expression.h"
#include "Plus.h"
#include "Number.h"
#include "Neg.h"

int main() {
    std::cout << "DBD LEGEND" << std::endl;
    Interpreter* check = new Interpreter("CommandTestFile.txt");
    Expression* exp = new Plus(new Neg(new Number(3.0)),
            new Number(5.0));
    std::cout << exp->calculate() << std::endl;
//    return 0;
//    cout << evaluate("10 + 2 * 6") << "\n";
//    cout << evaluate("100 * 2 + 12") << "\n";
//    cout << evaluate("100 * ( 2 + 12 )") << "\n";
//    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}
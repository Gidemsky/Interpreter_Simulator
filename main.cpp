#include <iostream>

#include "Interpreter.h"
#include "OpenDataServer.h"
#include "Condition.h"
#include "algorithm"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Connect.h"
#include "Data.h"
#include "Number.h"

Data data;

void shuntingYardTest() {
    ShuntingYard sy;
    string h = "h";
    data.setSymbolTable(h, 2);
    cout << sy.createExpression("h + 3")->calculate() << endl;
}

void shuntingYardTestFullTest() {
    Lexer *lexer = new Lexer("CommandTestFile.txt");
    string lexer_data = lexer->getFlightUserInput();
    Interpreter *parser = new Interpreter(lexer_data);
    parser->run();
}

void runTest() {
    Lexer *lexer = new Lexer("CommandTestFile.txt");
    string lexer_data = lexer->getFlightUserInput();
    Interpreter *parser = new Interpreter(lexer_data);
    parser->run();
    string port = "5400";
    string hrz = "10";
    OpenDataServer c = OpenDataServer(port, hrz);
    c.execute();
    Connect ce("127.0.0.1", "5402");
    ce.execute();
    pthread_exit(nullptr);
}

void expressionsTest() {
    string h = "h";
    data.setSymbolTable(h, 2);
    Number* a = new Number("h");
    cout << a->calculate() << endl;
}

int main() {
    //shuntingYardTest();
    expressionsTest();
}




#include <iostream>

#include "Interpreter.h"
#include "OpenDataServer.h"
#include "Condition.h"
#include "algorithm"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Connect.h"
#include "Data.h"

Data data;

void shuntingYardTest() {
    ShuntingYard sy;
    cout << sy.createExpression("15-200")->calculate() << endl;
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

int main() {
    shuntingYardTest();
}




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
#include "PrintCommand.h"
#include "IfCommand.h"

Data data;

/**
 * Working!
 */
void shuntingYardTest() {
    ShuntingYard sy;
    string h = "h";
    data.setSymbolTable(h, 2);
    cout << sy.createExpression("h + 3.2 + (h*3)-h-h")->calculate() << endl;
}

void runTest() {
    Lexer *lexer = new Lexer("CommandTestFile.txt");
    string lexer_data = lexer->getFlightUserInput();
    Interpreter *parser = new Interpreter(lexer_data);
    try {
        parser->run();
    } catch(string msg) {
        cout << msg << endl;
    }

    pthread_exit(nullptr);
}

/**
 * Working!
 */
void expressionsTest() {
    string h = "h";
    data.setSymbolTable(h, 2);
    Number* a = new Number("h");
    cout << a->calculate() << endl;
}

/**
 * Working!
 */
void printCommandTests() {
    // print sentence
    string t = "David";
    t = '"' + t;
    t = t + '"';
    // print variable
    string k = "h0";
    data.setSymbolTable("h0", 5);
    PrintCommand* p = new PrintCommand(k);
    p->execute();
}

void conditionalParserTests() {
    vector<CommandExpression*> cmds;
    string condition = "h > 3";
    data.setSymbolTable("h", 5);
    data.setSymbolTable("David", 3);
    //print
    string t = "David";
    t = '"' + t;
    t = t + '"';
    //print cmd
    PrintCommand* p = new PrintCommand(t);
    CommandExpression* print = new CommandExpression(p);
    cmds.push_back(print);

    // the second if in the scope
    IfCommand* i2 = new IfCommand(cmds, condition);
    CommandExpression* if2 = new CommandExpression(i2);
    cmds.push_back(if2);
    //condition parser command
    IfCommand* i = new IfCommand(cmds, condition);
    i->execute();
}

int main() {
    //shuntingYardTest();
    try {
        runTest();
    } catch (string msg) {
        cout << msg << endl;
    }
    //expressionsTest();
    //printCommandTests();
    //conditionalParserTests();
}
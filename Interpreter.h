//
// Created by gideon on 14/12/18.
//

#ifndef SIMULATOR_INTERPRETER_H
#define SIMULATOR_INTERPRETER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Data.h"
#include "Command.h"
#include "CommandExpression.h"

using namespace std;

class Interpreter {
    enum simulatorCommand{
        OPEN_DATA_SERVER, CONNECT,
        VAR, PRINT, SLEEP, INIT, CONDITIONAL
    };
    map<string,simulatorCommand> CMD_DICTIONARY = {
            {"openDataServer", OPEN_DATA_SERVER},
            {"connect", CONNECT},
            {"var", VAR},
            {"print", PRINT},
            {"sleep", SLEEP},
            {"while", CONDITIONAL},
            {"if", CONDITIONAL},
    };
    vector<vector<string>> victor; //my father's name
    int scope_count, expression_count;
    bool scope_open;
    vector<CommandExpression*> run_expressions;

public:
    Interpreter();
    Interpreter(string simulator_data);
    void DataParser(string strData, string strSpliter);
    CommandExpression* CommandCreator(vector<vector<string>> data);
    void runDataMap(string& name, CommandExpression* cmd_exp);
    void run();
};
//
#endif //SIMULATOR_INTERPRETER_H

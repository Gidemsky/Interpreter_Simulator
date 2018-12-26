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
        VAR, PRINT, SLEEP, INIT, TEMP, CONDITIONAL
    };
    map<string,simulatorCommand> CMD_DICTIONARY = {
            {"openDataServer", OPEN_DATA_SERVER},
            {"connect", CONNECT},
            {"var", VAR},
            {"print", PRINT},
            {"sleep", SLEEP},
            {"=", INIT},
            {"while", CONDITIONAL},
            {"if", CONDITIONAL},
            {"temp", TEMP}//temporary enum
    };
    bool isFileLoaded, scope_started;
    vector<vector<string>> victor; //my father's name
    int scope_count;
    fstream simulatorUserFile;
    string flightUserInput;
    Data* data;
public:
    Interpreter();
    explicit Interpreter(string userFileName);
    string fileReader(fstream *dataFile, bool isLoaded, string& userFileName);
    //template <class T>
    string lexer(string line, string split);
    vector<double> simLexer(string line, string split);
    void DataParser(string strData, string strSpliter);
    CommandExpression* CommandCreator(vector<vector<string>> data);
};

#endif //SIMULATOR_INTERPRETER_H

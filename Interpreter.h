//
// Created by gideon on 14/12/18.
//

#ifndef SIMULATOR_INTERPRETER_H
#define SIMULATOR_INTERPRETER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Data.h"
using namespace std;

class Interpreter {
    enum simulatorCommand{
        OPEN_DATA_SERVER, CONNECT,
        VAR, PRINT, SLEEP, INIT
    };
    map<string,simulatorCommand> CMD_DICTIONARY = {
            {"openDataServer", OPEN_DATA_SERVER},
            {"connect", CONNECT},
            {"var", VAR},
            {"print", PRINT},
            {"sleep", SLEEP},
            {"=", INIT}
    };
    bool isFileLoaded;
    fstream simulatorUserFile;
    string flightUserInput;
    Data data;
public:
    Interpreter();
    explicit Interpreter(string userFileName);
    string fileReader(fstream *dataFile, bool isLoaded, string& userFileName);
    string lexer(string line, string split);
    void DataParser(string strData, string strSpliter);
};

#endif //SIMULATOR_INTERPRETER_H

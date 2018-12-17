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
    bool isFileLoaded;
    fstream simulatorUserFile;
    string flightUserInput;
    Data data;
    //enum

public:
    Interpreter();
    explicit Interpreter(string userFileName);
    string fileReader(fstream *dataFile, bool isLoaded, string& userFileName);
    string lexer(string line, string split);
    void DataParser(string strData, string strSpliter);
};

#endif //SIMULATOR_INTERPRETER_H

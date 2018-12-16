//
// Created by gideon on 14/12/18.
//

#ifndef SIMULATOR_INTERPRETER_H
#define SIMULATOR_INTERPRETER_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Interpreter {
    bool isFileLoaded;
    fstream simulatorUserFile;
    string flightUserInput;
public:
    Interpreter();
    explicit Interpreter(string userFileName);
    string fileReader(fstream *dataFile, bool isLoaded, string& userFileName);
    string lexer(string line, string split);

};

#endif //SIMULATOR_INTERPRETER_H

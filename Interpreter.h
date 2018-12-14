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
    bool fileLoaded;
    fstream simulatorUserCode;
    string lexer;
public:
    Interpreter();
    Interpreter(fstream flightCode);
    void loadFileData(fstream *dataFile, bool *isLoaded);
};

#endif //SIMULATOR_INTERPRETER_H

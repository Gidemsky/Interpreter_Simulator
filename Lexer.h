//
// Created by gideon on 26/12/18.
//

#ifndef SIMULATOR_LEXER_H
#define SIMULATOR_LEXER_H
#include <algorithm>
#include <list>
#include "string"
#include "fstream"
#include <vector>
using namespace std;

class Lexer {
    string flightUserInput;
    fstream simulatorUserFile;
public:
    Lexer();
    Lexer(string userFileName);
    const string &getFlightUserInput() const;
    string fileReader(fstream *dataFile, string& userFileName);
    string lexer(string line, string split);
    vector<double> simLexer(string line, string split);
};


#endif //SIMULATOR_LEXER_H

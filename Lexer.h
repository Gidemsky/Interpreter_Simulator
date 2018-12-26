//
// Created by gideon on 26/12/18.
//

#ifndef SIMULATOR_LEXER_H
#define SIMULATOR_LEXER_H

#include "Lexer.h"
#include <algorithm>
#include <list>
#include "Interpreter.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "Connect.h"
#include "DefineVarCommand.h"
#include "Assign.h"
#include "LoopCommand.h"
#include "Sleep.h"

class Lexer {
    string flightUserInput;
    fstream simulatorUserFile;
    bool isFileLoaded;
public:
    Lexer(string userFileName);
    string fileReader(fstream *dataFile, bool isLoaded, string& userFileName);
    string lexer(string line, string split);
    vector<double> simLexer(string line, string split);
};


#endif //SIMULATOR_LEXER_H

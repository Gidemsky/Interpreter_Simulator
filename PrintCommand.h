//
// Created by benda on 24/12/18.
//

#ifndef SIMULATOR_PRINTCOMMAND_H
#define SIMULATOR_PRINTCOMMAND_H

#include "string"
#include "Command.h"
#include <iostream>

using namespace std;

class PrintCommand : public Command {
    string str;
public:
    PrintCommand(string str);
    virtual double execute();
};


#endif //SIMULATOR_PRINTCOMMAND_H

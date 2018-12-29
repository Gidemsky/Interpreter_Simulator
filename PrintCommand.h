
#ifndef SIMULATOR_PRINTCOMMAND_H
#define SIMULATOR_PRINTCOMMAND_H

#include "string"
#include "Command.h"
#include <iostream>
#include "Data.h"

using namespace std;

extern Data data;

class PrintCommand : public Command {
    string to_print;

public:
    PrintCommand(string str);
    virtual double execute();
};


#endif //SIMULATOR_PRINTCOMMAND_H

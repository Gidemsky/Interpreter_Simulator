//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H

#include "string"
using namespace std;

class Command {

public:
    virtual void execute() = 0;
};

#endif //SIMULATOR_COMMAND_H

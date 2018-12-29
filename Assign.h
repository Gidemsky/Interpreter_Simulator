
#ifndef SIMULATOR_ASSIGN_H
#define SIMULATOR_ASSIGN_H

#include "Command.h"
#include "Data.h"

extern Data data;

class Assign : public Command {
    string var;
    double value;

public:
    Assign(vector<string> params);
    virtual double execute();
};

#endif //SIMULATOR_ASSIGN_H

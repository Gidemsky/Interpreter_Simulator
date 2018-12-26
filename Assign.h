//
// Created by gideon on 20/12/18.
//

#ifndef SIMULATOR_ASSIGN_H
#define SIMULATOR_ASSIGN_H

#include "Command.h"
#include "Data.h"

extern Data data;
class Assign : public Command {

    string left, right;
public:
    Assign(vector<string> parameters);
    double execute();
};


#endif //SIMULATOR_ASSIGN_H

//
// Created by gideon on 20/12/18.
//

#ifndef SIMULATOR_ASSIGN_H
#define SIMULATOR_ASSIGN_H

#include "Command.h"
#include "Data.h"


class Assign : public Command {
    Data data;
    string left, right;
public:
    Assign(vector<string> parameters);
    double execute();
};


#endif //SIMULATOR_ASSIGN_H

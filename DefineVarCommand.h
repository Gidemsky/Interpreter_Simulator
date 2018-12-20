//
// Created by gideon on 20/12/18.
//

#ifndef SIMULATOR_DEFINEVARCOMMAND_H
#define SIMULATOR_DEFINEVARCOMMAND_H

#include <vector>
#include "Command.h"
#include "Data.h"

class DefineVarCommand : public Command {
    Data data;
    string left, right;
    enum ASSIGN_TYPE {BIND, VAR, UPDATE};
public:
    DefineVarCommand(vector<string> parameters);
    double execute();
};

#endif //SIMULATOR_DEFINEVARCOMMAND_H

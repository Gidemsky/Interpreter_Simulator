//
// Created by gideon on 20/12/18.
//

#ifndef SIMULATOR_DEFINEVARCOMMAND_H
#define SIMULATOR_DEFINEVARCOMMAND_H

#include <vector>
#include "Command.h"
#include "Data.h"

class DefineVarCommand : public Command {
    Data* data;
    string left, right;
    //enum VAR_TYPE {BIND, LCL_VAR};
    bool is_local_var;
public:
    DefineVarCommand(vector<string> parameters,Data* data);
    string getLeft();
    string getRight();
    double execute() override;
};

#endif //SIMULATOR_DEFINEVARCOMMAND_H

//
// Created by gideon on 20/12/18.
//

#ifndef SIMULATOR_DEFINEVARCOMMAND_H
#define SIMULATOR_DEFINEVARCOMMAND_H

#include <vector>
#include "Command.h"

class DefineVarCommand : public Command {
    //Data* data;
    string left, right;
    bool is_local_var;
public:
    DefineVarCommand(vector<string> parameters);
    string getLeft();
    string getRight();
    double execute() override;
};

#endif //SIMULATOR_DEFINEVARCOMMAND_H

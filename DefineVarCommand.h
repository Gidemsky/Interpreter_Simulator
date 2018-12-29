
#ifndef SIMULATOR_DEFINEVARCOMMAND_H
#define SIMULATOR_DEFINEVARCOMMAND_H

#include <vector>
#include "Command.h"
#include "string"
#include "Data.h"

extern Data data;

class DefineVarCommand : public Command {
    string left;
    string right;

public:
    DefineVarCommand(vector<string> parameters);
    double execute() override;
};

#endif //SIMULATOR_DEFINEVARCOMMAND_H

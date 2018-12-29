
#include "DefineVarCommand.h"

#define BIND "bind"
#define VAR_INDEX 1
#define PATH_INDEX 4
#define INIT_VALUE 0

/**
 * Ctor.
 * @param parameters
 */
DefineVarCommand::DefineVarCommand(vector<string> parameters) {
    if (find(parameters.begin(), parameters.end(), BIND) != parameters.end()) {
        this->left = parameters[VAR_INDEX];
        this->right = parameters[PATH_INDEX];
        data.setBinds(left, right);
        data.setSymbolTable(left, INIT_VALUE);
    } else {
        this->left = parameters[1];
        this->right = parameters[3];
        data.setSymbolTable(left,0);
    }
}

/**
 * Override.
 * @return
 */
double DefineVarCommand::execute() {
    return 0;
}

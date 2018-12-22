//
// Created by gideon on 20/12/18.
//

#include <algorithm>
#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(vector<string> parameters) {
    if (find(parameters.begin(), parameters.end(),"bind")!=parameters.end()){
        this->left = parameters[1];
        this->right = parameters[4];
        this->is_local_var= false;
    } else {
        this->left = parameters[1];
        this->right = parameters[3];
        this->is_local_var= true;
    }
}

double DefineVarCommand::execute() {
    if (is_local_var){
        data.setLocal_var(left,right);
    } else {
        data.setBinds(left,right);
    }
    return 0;
}

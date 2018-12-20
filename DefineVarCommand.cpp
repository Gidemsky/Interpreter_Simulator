//
// Created by gideon on 20/12/18.
//

#include <algorithm>
#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(vector<string> parameters) {
    if (find(parameters.begin(), parameters.end(),"=")!=parameters.end()){
        if (find(parameters.begin(), parameters.end(),"bind")!=parameters.end()){
            this->left = parameters[1];
            this->right = parameters[4];
        } else {
            if (parameters[0]=="var"){
                this->left = parameters[1];
                this->right = parameters[3];
            } else {
                this->left = parameters[0];
                this->right = parameters[2];
            }
        }
    }
}

double DefineVarCommand::execute() {

    return 0;
}

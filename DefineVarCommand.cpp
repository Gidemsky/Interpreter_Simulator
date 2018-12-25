//
// Created by gideon on 20/12/18.
//

#include <algorithm>
#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(vector<string> parameters, Data* data) {
    if (find(parameters.begin(), parameters.end(),"bind")!=parameters.end()){
        this->left = parameters[1];
        this->right = parameters[4];
        this->is_local_var= false;
    } else {
        this->left = parameters[1];
        this->right = parameters[3];
        this->is_local_var= true;
    }
    if (is_local_var){
        data->setLocal_var(left,right);
    } else {
        data->setBinds(left,right);
    }
}

double DefineVarCommand::execute() {
//    if (is_local_var){
//        data.setLocal_var(left,right);
//    } else {
//        data.setBinds(left,right);
//    }
    return 0;
}

string DefineVarCommand::getLeft(){
    return this->left;
}
string DefineVarCommand::getRight(){
    return this->right;
}

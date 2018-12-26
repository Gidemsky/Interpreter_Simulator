//
// Created by gideon on 20/12/18.
//

#include <algorithm>
#include "DefineVarCommand.h"
#include "Data.h"

extern Data data;
DefineVarCommand::DefineVarCommand(vector<string> parameters) {
    if (find(parameters.begin(), parameters.end(),"bind")!=parameters.end()){
        this->left = parameters[1];
        this->right = parameters[4];
        data.setBinds(left,right);
        data.setSymbolTable(left,0);
        //this->is_local_var= false;
    } else {
        this->left = parameters[1];
        this->right = parameters[3];
        data.setSymbolTable(left,0);
    }
//    if (is_local_var){
//        //data.setLocal_var(left,right);
//    } else {
//        //data.setBinds(left,right);
//    }
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

//
// Created by gideon on 17/12/18.
//

#ifndef SIMULATOR_DATA_H
#define SIMULATOR_DATA_H

#include <map>
#include <string>
#include <vector>
#include "Expression.h"
#include "Lexer.h"

using namespace std;

class Data {
    Lexer lexer;
    //map<string,double> planeData;
    map<string,Expression*> simulator_data;
public:
    const map<string, Expression *> &getSimulator_data() const;

private:
//the final map - <string,CommandExpression>
    map<string,string> binds;//the final map - <string,bind>
    map<string,string> local_var;//TODO: delete
    map<string,double> symbol_table;
    /* data from the xml: */
    vector<string> paths;
    map<string, double> path_values;

public:
    //setter and getter to simData
    void setSimulatorData(string cmd,  Expression* ce);

    //setter and getter to setBind
    void setBinds(string var_name, string path);
    const map<string, string> &getBinds() const;

    //setter and getter to symbol table
    void setSymbolTable(string symbol, double value);
    const map<string, double> &getSymbolTable() const;

    //void setLocal_var(string var_name, string value);

    void initializePaths();
    vector<string> getPaths();
    void initializePathValues();
    void setPathValues(string values);
    map<string, double> getPathValues();
};

#endif //SIMULATOR_DATA_H

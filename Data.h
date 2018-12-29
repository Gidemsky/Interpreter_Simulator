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
#include "CommandExpression.h"

using namespace std;

class Data {
    Lexer lexer;
    map<string, Expression *> simulator_data;
    map<string, string> binds;
    map<string, double> symbol_table;
    vector<string> paths;
    map<string, double> path_values;
    map<string, string> var_path;
    bool is_new_data = false;
    vector<pair<string, double>> new_plane_data;

public:
    const vector<pair<string, double>> &getNewPlaneData() const;

    void setNewPlaneData(string var, double val);

    //setter and getter to simData
    void setSimulatorData(string cmd, Expression* ce);

    //setter and getter to setBind
    void setBinds(string var_name, string path);
    string getBind(string var);

    //setter and getter to symbol table
    void setSymbolTable(string symbol, double value);
    const map<string, double> &getSymbolTable() const;

    //void setLocal_var(string var_name, string value);

    void initializePaths();
    vector<string> getPaths();
    const map<string, Expression *> &getSimulator_data() const;
    void initializePathValues();
    void setPathValues(string values);
    map<string, double> getPathValues();

    vector<CommandExpression*> getCommands();

    double getValue(string var);
    map<string,string>& getBinds();

    bool IsNewData();
    void setIsNewData(bool b);
    void clearNewPlaneData();
};

#endif //SIMULATOR_DATA_H

//
// Created by gideon on 17/12/18.
//

#ifndef SIMULATOR_DATA_H
#define SIMULATOR_DATA_H

#include <map>
#include <mutex>
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
    bool is_new_data = false;
    vector<pair<string, double>> new_plane_data;
    vector<pair<string, double>> path_value;
    mutable mutex m;

public:

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
    void initializePathValues();
    void setPathValues(string values);



    double getValue(string var);
    map<string,string>& getBinds();

    void setIsNewData(bool b);

    auto get_and_clear() {
        lock_guard<mutex> g(m);
        auto output = new_plane_data;
        new_plane_data.clear();
        return output;
    }

    void update_path_value(int index, double value)   {
        path_value[index].second = value;
        string path = path_value[index].first;

        for (auto& it : binds)  {
            string alt_path = it.second.substr(1, it.second.length() - 2);
            if (it.second == path || alt_path == path)  {
                symbol_table[it.first] = value;
            }
        }
    }
};

#endif //SIMULATOR_DATA_H

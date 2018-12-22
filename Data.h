//
// Created by gideon on 17/12/18.
//

#ifndef SIMULATOR_DATA_H
#define SIMULATOR_DATA_H

#include <map>
#include <string>
#include <vector>
#include "Expression.h"

using namespace std;

class Data {
    //map<string,double> planeData;
    map<string,string> planeData;
    map<string,string> simulatorData;
    map<string,Expression*> simData;//the final map
    map<string,double> airplaneData;//the final map
    map<string,string> binds;//maybe the final map
    map<string,string> local_var;//TODO: check changing the value to double
public:
    const map<string, string> &getBinds() const;
    const map<string, double> &getAirplaneData() const;
    void setAirplaneData(string symbol, double value);
    void setBinds(const map<string, string> &binds);
    void setBinds(string var_name, string path);

    const map<string, string> &getLocal_var() const;

    void setLocal_var(string var_name, string value);

    void setPlaneData(string symbol, string value);
    void setPlaneData(vector<string> planeData);
    void setSimulatorData(string cmd, string expression);
    void setSimulatorData(string cmd,  Expression* ce);
    void setSimulatorData(vector<string> cmdData);

    const map<string,double> &getPlaneData() const;

    //void setPlaneData(const map<string,string> &planeData);

    const map <string, string> &getSimulatorData() const;

    void setSimulatorData(const map <string, string> &simulatorData);
};


#endif //SIMULATOR_DATA_H

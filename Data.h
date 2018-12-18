//
// Created by gideon on 17/12/18.
//

#ifndef SIMULATOR_DATA_H
#define SIMULATOR_DATA_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Data {
    //map<string,double> planeData;
    map<string,string> planeData;
    map<string,string> simulatorData;
    map<string,string> binds;
public:
    const map<string, string> &getBinds() const;

    void setBinds(const map<string, string> &binds);
    void setBinds(vector<string> binders);
    //void setPlaneData(string symbol, string value);
    void setPlaneData(vector<string> planeData);
    void setSimulatorData(string cmd, string expression);
    void setSimulatorData(vector<string> cmdData);

    const map<string,double> &getPlaneData() const;

    //void setPlaneData(const map<string,string> &planeData);

    const map <string, string> &getSimulatorData() const;

    void setSimulatorData(const map <string, string> &simulatorData);
};


#endif //SIMULATOR_DATA_H

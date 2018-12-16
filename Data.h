//
// Created by gideon on 17/12/18.
//

#ifndef SIMULATOR_DATA_H
#define SIMULATOR_DATA_H

#include <map>
#include <string>

using namespace std;

class Data {
    map<string,double > planeData;
    map<string,string > simulatorData;
public:
    void setPlaneData(string symbol, string value);
    void setSimulatorData(string cmd, string expression);

    const map<string,double> &getPlaneData() const;

    void setPlaneData(const map<string,double> &planeData);

    const map <string, string> &getSimulatorData() const;

    void setSimulatorData(const map <string, string> &simulatorData);
};


#endif //SIMULATOR_DATA_H

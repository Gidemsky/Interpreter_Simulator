//
// Created by gideon on 17/12/18.
//

#include "Data.h"

const map<string, double> &Data::getPlaneData() const {
    return planeData;
}

void Data::setPlaneData(const map<string, double> &planeData) {
    Data::planeData = planeData;
}

const map <string, string> &Data::getSimulatorData() const {
    return simulatorData;
}

void Data::setSimulatorData(const map <string, string> &simulatorData) {
    Data::simulatorData = simulatorData;
}

void Data::setPlaneData(string symbol, string value) {
    this->planeData.insert(pair<string, double>(symbol, stoi(value)));
}

void Data::setSimulatorData(string cmd, string expression) {
    this->simulatorData.insert(pair<string, string>(cmd, expression));
}

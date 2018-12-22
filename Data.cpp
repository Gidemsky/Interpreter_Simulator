//
// Created by gideon on 17/12/18.
//

#include "Data.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"

//const map<string, double> &Data::getPlaneData() const {
//    return planeData;
//}

//void Data::setPlaneData(const map<string, double> &planeData) {
//    Data::planeData = planeData;
//}

const map <string, string> &Data::getSimulatorData() const {
    return simulatorData;
}

void Data::setSimulatorData(const map <string, string> &simulatorData) {
    Data::simulatorData = simulatorData;
}

//void Data::setPlaneData(string symbol, string value) {
//    this->planeData.insert(pair<string, double>(symbol, stoi(value)));
//}

void Data::setSimulatorData(string cmd, string expression) {
    this->simulatorData.insert(pair<string, string>(cmd, expression));
}

void Data::setPlaneData(vector<string> planeData) {
    int size_t = static_cast<int>(planeData.size());
    string data;
    for(int i=2;i<(size_t-1);i++){
        data += planeData[i];
    }
    data += planeData[size_t-1];
    this->planeData.insert(pair<string, string>(planeData[0],data));
}

void Data::setSimulatorData(vector<string> cmdData) {
    //new CommandExpression(new OpenDataServer(stod(cmdData[1]),stod(cmdData[2])));
    int size_t = static_cast<int>(cmdData.size());
    string data;
    for(int i=1;i<(size_t-1);i++){
        data += cmdData[i] + " ";
    }
    data += cmdData[size_t-1];
    this->simulatorData.insert(pair<string, string>(cmdData[0],data));
}

const map<string, string> &Data::getBinds() const {
    return binds;
}

void Data::setBinds(const map<string, string> &binds) {
    Data::binds = binds;
}

void Data::setBinds(string var_name, string path) {
    this->binds.insert(pair<string, string>(var_name,path));
//    int size_t = static_cast<int>(binders.size());
//    string data;
//    for(int i=2;i<(size_t-1);i++){
//        data += binders[i] + " ";
//    }
//    data += binders[size_t-1];
//    this->binds.insert(pair<string, string>(binders[1],data));
}

void Data::setSimulatorData(string cmd, Expression *ce) {
    this->simData.insert(pair<string, Expression*>(cmd,ce));
}

const map<string, double> &Data::getAirplaneData() const {
    return airplaneData;
}

void Data::setAirplaneData(string symbol, double value) {
    this->airplaneData.insert(pair<string, double>(symbol,value));
}

const map<string, string> &Data::getLocal_var() const {
    return local_var;
}

void Data::setLocal_var(string var_name, string value) {
    this->local_var.insert(pair<string, string>(var_name,value));
}


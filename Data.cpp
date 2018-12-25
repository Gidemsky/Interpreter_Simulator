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

void Data::setSimData(string cmd, Expression *ce) {
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

void Data::initializePaths() {
   this->paths = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                "/instrumentation/altimeter/indicated-altitude-ft",
                "/instrumentation/altimeter/pressure-alt-ft",
                "/instrumentation/attitude-indicator/indicated-pitch-deg",
                "/instrumentation/attitude-indicator/indicated-roll-deg",
                "/instrumentation/attitude-indicator/internal-pitch-deg",
                "/instrumentation/attitude-indicator/internal-roll-deg",
                "/instrumentation/encoder/indicated-altitude-ft",
                "/instrumentation/encoder/pressure-alt-ft",
                "/instrumentation/gps/indicated-altitude-ft",
                "/instrumentation/gps/indicated-ground-speed-kt",
                "/instrumentation/gps/indicated-vertical-speed",
                "/instrumentation/heading-indicator/indicated-heading-deg",
                "/instrumentation/magnetic-compass/indicated-heading-deg",
                "/instrumentation/slip-skid-ball/indicated-slip-skid",
                "/instrumentation/turn-indicator/indicated-turn-rate",
                "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                "/controls/flight/aileron",
                "/controls/flight/elevator",
                "/controls/flight/rudder",
                "/controls/flight/flaps",
                "/controls/engines/engine/throttle",
                "/engines/engine/rpm"};
}

vector<string> Data::getPaths() {
    return this->paths;
}

void Data::initializePathValues() {
    // initialize all the paths with 0
    for (string path : this->getPaths()) {
        this->path_values.insert(pair<string, double>(path, 0));
    }
}

//void Data::setPathValues(string data) {
//    vector<double> values = this->interpreter.simLexer(data, ",");
//
//}
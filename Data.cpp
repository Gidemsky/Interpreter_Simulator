//
// Created by gideon on 17/12/18.
//

#include "Data.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "iostream"

/**
 *
 * @param cmd
 * @param ce
 */
void Data::setSimulatorData(string cmd, Expression *ce) {
    this->simulator_data.insert(pair<string, Expression*>(cmd,ce));
}
//TODO: check if sim data getter is needed

/**
 *
 * @return
 */
const map<string, string> &Data::getBinds() const {
    return binds;
}
/**
 *
 * @param var_name
 * @param path
 */
void Data::setBinds(string var_name, string path) {
    this->binds.insert(pair<string, string>(var_name,path));
}

/**
 *
 * @param symbol
 * @param value
 */
void Data::setSymbolTable(string symbol, double value) {
    this->symbol_table.insert(pair<string, double>(symbol,value));
}
/**
 *
 * @return
 */
const map<string, double> &Data::getSymbolTable() const {
    return this->symbol_table;
}

/**
 * Initialize the xml paths.
 */
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
/**
 *
 */
void Data::initializePathValues() {
    // initialize all the paths with 0
    for (string path : this->getPaths()) {
        this->path_values.insert(pair<string, double>(path, 0));
    }
}
/**
 * Initialize all the path values to 0.
 * @param data
 */
void Data::setPathValues(string data) {
    // get the values from the xml
    vector<double> values = this->lexer.simLexer(data, ",");
    map<string, double>::iterator it;

    // set the data
    for (int i = 0; i < this->paths.size(); i++) {
        it = this->path_values.find(this->paths[i]);
        if (it != this->path_values.end()) {
            it->second = values[i];
        }
    }
}

map<string, double> Data::getPathValues() {
    return this->path_values;
}

const map<string, Expression *> &Data::getSimulator_data() const {
    return simulator_data;
}
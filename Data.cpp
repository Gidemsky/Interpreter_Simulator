
#include "Data.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "iostream"
#include <list>

/**
 *
 * @param cmd
 * @param ce
 */
void Data::setSimulatorData(string cmd, Expression *ce) {
    this->simulator_data.insert(pair<string, Expression *>(cmd, ce));
}

/**
 *
 * @return
 */
string Data::getBind(string var) {
    return this->binds[var];
}

/**
 *
 * @param var_name
 * @param path
 */
void Data::setBinds(string var_name, string path) {
    this->binds.insert(pair<string, string>(var_name, path));
}

/**
 *
 * @param symbol
 * @param value
 */
void Data::setSymbolTable(string symbol, double value) {
    if(this->symbol_table.find(symbol) == this->symbol_table.end()){
        this->symbol_table.insert(pair<string, double>(symbol, value));
    } else {
        this->symbol_table[symbol]=value;
    }
}

/**
 *
 * @return
 */
const map<string, double> &Data::getSymbolTable() const {
    return this->symbol_table;
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
 * Initialize all the path values.
 * @param data
 */
void Data::setPathValues(string data) {
    // get the values from the xml
    vector<double> values = this->lexer.simLexer(data, ",");

    for (int i = 0; i < this->path_value.size(); i++) {
        update_path_value(i, values[i]);
    }
}


/**
 * Getter of var's value from the symbol table.
 * @param var
 * @return the value.
 */
double Data::getValue(string var) {
    map<string, double>::iterator it;
    // get the value from the symbol table
    it = this->symbol_table.find(var);
    if (it != this->symbol_table.end()) {
        return it->second;
    }
    // get the value from the path values
    map<string, string>::iterator second_it;
    second_it = this->binds.find(var);
    if (second_it != this->binds.end()) {
        it = this->path_values.find(second_it->second);
        if (it != this->path_values.end()) {
            return it->second;
        }
    } else {
        throw "The variable " + var + " doesn't exist in the symbol table";
    }
}

void Data::setNewPlaneData(string var, double val) {
    lock_guard<mutex> g(m);
    this->new_plane_data.emplace_back(var, val);
}

map<string, string> &Data::getBinds() {
    return this->binds;
}

void Data::initializePaths() {
    this->path_value = {pair<string, double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0),
                        pair<string, double>("/instrumentation/altimeter/indicated-altitude-ft", 0),
                        pair<string, double>("/instrumentation/altimeter/pressure-alt-ft", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg", 0),
                        pair<string, double>("/instrumentation/encoder/indicated-altitude-ft", 0),
                        pair<string, double>("/instrumentation/encoder/pressure-alt-ft", 0),
                        pair<string, double>("/instrumentation/gps/indicated-altitude-ft", 0),
                        pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt", 0),
                        pair<string, double>("/instrumentation/gps/indicated-vertical-speed", 0),
                        pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg", 0),
                        pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0),
                        pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0),
                        pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate", 0),
                        pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0),
                        pair<string, double>("/controls/flight/aileron", 0),
                        pair<string, double>("/controls/flight/elevator", 0),
                        pair<string, double>("/controls/flight/rudder", 0),
                        pair<string, double>("/controls/flight/flaps", 0),
                        pair<string, double>("/controls/engines/engine/throttle", 0),
                        pair<string, double>("/engines/engine/rpm", 0)};
}

void Data::update_path_value(int index, double value)   {
    path_value[index].second = value;
    string path = path_value[index].first;

    for (auto& it : binds)  {
        string alt_path = it.second.substr(1, it.second.length() - 2);
        if (it.second == path || alt_path == path)  {
            symbol_table[it.first] = value;
        }
    }
}

void Data::setRunning(bool b) {
    this->running = b;
}

bool Data::getRunning() {
    return this->running;
}

//void Data::setCeToDel(Expression *ce) {
//    this->ce_to_del.push_back(ce);
//}

//void Data::clean_data() {
//    int i;
//    while(this->simulator_data.size() != 0){
//        i = this->simulator_data.begin();
//    }
//}

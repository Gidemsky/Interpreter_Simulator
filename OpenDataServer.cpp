#include <utility>

//
// Created by gideon on 18/12/18.
//
#include <iostream>
#include "OpenDataServer.h"

double OpenDataServer::getPort() const {
    return port;
}

void OpenDataServer::setPort(double port) {
    OpenDataServer::port = port;
}

double OpenDataServer::getHz() const {
    return hz;
}

void OpenDataServer::setHz(double hz) {
    OpenDataServer::hz = hz;
}

double OpenDataServer::execute() {
    std::cout<<"to something"<<std::endl;
    return 0;
}

OpenDataServer::OpenDataServer(string& port, string& hz) {
    ShuntingYard shuntingYard;
    this->port=shuntingYard.createExpression(port)->calculate();
    this->hz=shuntingYard.createExpression(hz)->calculate();
}

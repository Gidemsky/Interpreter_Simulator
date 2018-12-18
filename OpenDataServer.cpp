//
// Created by gideon on 18/12/18.
//
#include <iostream>
#include "OpenDataServer.h"

OpenDataServer::OpenDataServer(double port, double hz) : port(port), hz(hz) {}

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
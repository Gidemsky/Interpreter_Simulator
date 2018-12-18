//
// Created by gideon on 18/12/18.
//

#include "Connect.h"

Connect::Connect(const string &ip_address, const string &port) : ip_address(ip_address), port(port) {}

const string &Connect::getIp_address() const {
    return ip_address;
}

void Connect::setIp_address(const string &ip_address) {
    Connect::ip_address = ip_address;
}

const string &Connect::getPort() const {
    return port;
}

void Connect::setPort(const string &port) {
    Connect::port = port;
}

void Connect::execute() {

}
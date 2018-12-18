//
// Created by gideon on 18/12/18.
//

#include "Connect.h"

Connect::Connect(const string &ip_address, string& port) {
    ShuntingYard shuntingYard;
    this->ip_address=ip_address;
    this->port = shuntingYard.createExpression(port)->calculate();
}

const string &Connect::getIp_address() const {
    return ip_address;
}

void Connect::setIp_address(const string &ip_address) {
    Connect::ip_address = ip_address;
}

double Connect::execute() {

}

//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_CONNECT_H
#define SIMULATOR_CONNECT_H

#include "Command.h"
#include "ShuntingYard.h"

class Connect : public Command{
    string ip_address;
    double port;
public:

    double execute();//TODO:check maybe we need to do override

    Connect(const string &ip_address, string& port);

    const string &getIp_address() const;

    void setIp_address(const string &ip_address);
};

#endif //SIMULATOR_CONNECT_H
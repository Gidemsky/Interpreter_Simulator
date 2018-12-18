//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_CONNECT_H
#define SIMULATOR_CONNECT_H

#include "Command.h"

class Connect : public Command{
    string ip_address;
    string port;
public:
    Connect(const string &ip_address, const string &port);

    void execute();

    const string &getIp_address() const;

    void setIp_address(const string &ip_address);

    const string &getPort() const;

    void setPort(const string &port);
};


#endif //SIMULATOR_CONNECT_H

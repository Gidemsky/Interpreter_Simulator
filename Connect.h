
#ifndef SIMULATOR_CONNECT_H
#define SIMULATOR_CONNECT_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include "Command.h"
#include "ShuntingYard.h"
#include "Data.h"
#include <iostream>
//
extern Data data;

class Connect : public Command{
    string ip_address;
    double port;

public:
    Connect(string ip_address, string port);
    static void* runClient(void* args);
    double execute();
};

#endif //SIMULATOR_CONNECT_H

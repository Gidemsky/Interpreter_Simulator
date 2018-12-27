//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_OPENDATASERVER_H
#define SIMULATOR_OPENDATASERVER_H

#include "Command.h"
#include "ShuntingYard.h"
#include "Data.h"

class OpenDataServer : public Command{
    unsigned short port;
    short hz;

public:
    OpenDataServer(string port, string hz);
    static void* readFromServer(void* params);
    double execute() override;
};

#endif //SIMULATOR_OPENDATASERVER_H
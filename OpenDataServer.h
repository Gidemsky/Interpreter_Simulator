//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_OPENDATASERVER_H
#define SIMULATOR_OPENDATASERVER_H

#include "Command.h"
#include "ShuntingYard.h"

class OpenDataServer : public Command{
    double port;
    double hz;

public:

    double getPort() const;

    OpenDataServer(string& port, string& hz);

    void setPort(double port);

    double getHz() const;

    void setHz(double hz);

    double execute();
};

#endif //SIMULATOR_OPENDATASERVER_H
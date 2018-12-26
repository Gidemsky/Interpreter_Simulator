//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_OPENDATASERVER_H
#define SIMULATOR_OPENDATASERVER_H

#include "Command.h"
#include "ShuntingYard.h"
#include "Data.h"

class OpenDataServer : public Command{
    double port;
    double hz;
    Data* data;

public:

    OpenDataServer(string& port, string& hz, Data* data);

    double getPort() const;


    void setPort(double port);

    double getHz() const;

    void setHz(double hz);

    double execute();
};

#endif //SIMULATOR_OPENDATASERVER_H
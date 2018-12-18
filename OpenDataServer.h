//
// Created by gideon on 18/12/18.
//

#ifndef SIMULATOR_OPENDATASERVER_H
#define SIMULATOR_OPENDATASERVER_H

#include "Command.h"


class OpenDataServer : public Command{
    double port;
    double hz;
public:
    OpenDataServer(double port, double hz);

    double getPort() const;

    void setPort(double port);

    double getHz() const;

    void setHz(double hz);

    void execute();
};


#endif //SIMULATOR_OPENDATASERVER_H

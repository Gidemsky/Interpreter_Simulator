//
// Created by gideon on 19/12/18.
//

#ifndef SIMULATOR_SLEEP_H
#define SIMULATOR_SLEEP_H

#include "Command.h"
#include "chrono"
#include "thread"
#include "ShuntingYard.h"


class Sleep : public Command{
    int millisec;
public:
    Sleep(string& millisec);
    double execute();
};


#endif //SIMULATOR_SLEEP_H

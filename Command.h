
#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H

using namespace std;

class Command {

public:
    virtual double execute() = 0;
};

#endif //SIMULATOR_COMMAND_H

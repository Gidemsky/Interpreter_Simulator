//
// Created by gideon on 19/12/18.
//

#include "Sleep.h"

Sleep::Sleep(string& millisec) {
    ShuntingYard shuntingYard;
    //cast 'double' into the receiver type 'int'
    this->millisec = static_cast<int>
            (shuntingYard.createExpression(millisec)->calculate());
}

double Sleep::execute() {
    this_thread::sleep_for(chrono::milliseconds(this->millisec));
    return 0;
}

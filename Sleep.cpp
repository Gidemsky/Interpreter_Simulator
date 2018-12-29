
#include "Sleep.h"

/**
 * Ctor.
 * @param millisec
 */
Sleep::Sleep(string& milliseconds) {
    ShuntingYard shuntingYard;
    this->milliseconds = static_cast<int>
            (shuntingYard.createExpression(milliseconds)->calculate());
}

/**
 * Execute the sleep.
 * @return
 */
double Sleep::execute() {
    this_thread::sleep_for(chrono::milliseconds(this->milliseconds));
    return 0;
}

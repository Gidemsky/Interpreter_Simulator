
#include "PrintCommand.h"

/**
 * Ctor.
 * @param str
 */
PrintCommand::PrintCommand(string str) {
    this->str = str;
}

/**
 * Print.
 * @return
 */
double PrintCommand::execute() {
    cout << this->str << endl;
    return 0;
}
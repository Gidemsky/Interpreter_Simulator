
#include "PrintCommand.h"

/**
 * Ctor.
 * @param str
 */
PrintCommand::PrintCommand(string str) {
    this->to_print = str;
}

/**
 * Print.
 * @return
 */
double PrintCommand::execute() {
    string str = this->to_print;
    // if it's a sentence
    if ((str[0] == '"') && (str[str.length() - 1] = '"')) {
        str.erase(0, 1);
        str.erase(str.length() - 1, 1);
        cout << str << endl;
        return 0;
    }
    // if it's a variable
    else {
        cout << data.getValue(str) << endl;
    }
    return 0;
}
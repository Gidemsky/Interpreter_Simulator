//
// Created by benda on 27/12/18.
//

#include "RunFlow.h"

/**
 * Run Flow.
 */
void RunFlow::run() {
    // get the list of the commands
    vector<CommandExpression*> commands = data.getCommands();
    // execute the commands
    for (CommandExpression* cmd : commands) {
        cmd->calculate();
    }
}
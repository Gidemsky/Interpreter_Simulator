//
// Created by benda on 26/12/18.
//

#include "CmdTest.h"

CmdTest::CmdTest(vector<CommandExpression *> cmds, string cond, Data *d) {
    this->cmds = cmds;
    this->cond = cond;
    this->d = d;
}

double CmdTest::execute() {
    int k = 0;
}
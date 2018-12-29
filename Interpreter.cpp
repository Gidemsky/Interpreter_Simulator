//
// Created by gideon on 14/12/18.
//

#include <algorithm>
#include <list>
#include "Interpreter.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "Connect.h"
#include "DefineVarCommand.h"
#include "Assign.h"
#include "LoopCommand.h"
#include "Sleep.h"
#include "Data.h"
#include "PrintCommand.h"


#define CMD_SPLIT "#"
#define CMD_PARAMETER "|"
#define SIM_INPUT_SPLIT ","
#define FILE_SPACE " "

extern Data data;

/**
 * Interpreter's Constructor
 */
Interpreter::Interpreter(){
    isFileLoaded = false;//TODO:add the flight user data from the Cin?
    this->scope_count=0;
    isFileLoaded = false;//TODO:check if necessary
    this->scope_started = false;
}

Interpreter::Interpreter(string simulator_data){
    isFileLoaded = false;//TODO:add the flight user data from the Cin?
    this->scope_count=0;
    isFileLoaded = false;//TODO:check if necessary
    this->scope_started = false;
    DataParser(simulator_data,CMD_SPLIT);
    CommandCreator(this->victor);
}

void Interpreter::DataParser(string strData, string strSpliter) {
    vector<string> cmdData;
    string lineData = strData;
    size_t pos = 0;
    string cmdParameters;
    if (strSpliter == CMD_SPLIT) {
        while ((pos = lineData.find(strSpliter)) != string::npos) {
            cmdParameters = lineData.substr(0, pos);
            DataParser(cmdParameters, CMD_PARAMETER);
            lineData.erase(0, pos + 1);
        }
        cmdData.push_back(lineData);
    } else {
        while ((pos = lineData.find(strSpliter)) != string::npos) {
            cmdParameters = lineData.substr(0, pos);//TODO:check if might be faster only with one substring
            cmdData.push_back(cmdParameters);
            lineData.erase(0, pos + 1);
        }
        cmdData.push_back(lineData);
        this->victor.push_back(cmdData);
    }
}

CommandExpression *Interpreter::CommandCreator(vector<vector<string>> parameters) {
    while (!parameters.empty()) {//parameter not empty
        vector<string> param;
        param = parameters.at(0);
        parameters.erase(parameters.begin());
        simulatorCommand commandClass = VAR;
        if (find(param.begin(), param.end(), "=") != param.end()) {
            commandClass = INIT;
            if (find(param.begin(), param.end(), "var") != param.end()) {
                commandClass = VAR;
            }
        } else if (CMD_DICTIONARY.find(param[0]) != CMD_DICTIONARY.end()) {
            commandClass = CMD_DICTIONARY[param[0]];//TODO: add the switch case issues to function
        } else {
            if (param[0] == "}") {
                return 0;
            } else if (this->scope_count == 0) {
            }
            commandClass = CMD_DICTIONARY["="];
            if (param[0] == "while" || param[0] == "}") {//temporary condition
                commandClass = CMD_DICTIONARY["temp"];//temporary condition
            }
        }
        CommandExpression *ce;
        switch (commandClass) {
            case OPEN_DATA_SERVER: {
                ce = new CommandExpression(new OpenDataServer(param[1], param[2]));//TODO: add calculate
                data.setSimulatorData(param[0], ce);
                this->cmd_expressions.push_back(ce);
                //return ce;
                break;
            }
            case CONNECT: {
                ce = new CommandExpression(new Connect(param[1], param[2]));
                data.setSimulatorData(param[0], ce);
                this->cmd_expressions.push_back(ce);
                //return ce;
                break;
            }
            case VAR: {
                ce = new CommandExpression(new DefineVarCommand(param));
                if(param[0] != "var") {
                    data.setSimulatorData(param[0]+param[1]+param[2], ce);
                    return ce;
                }
                else {
                    break;
                }
            }
            case CONDITIONAL: {
                bool is_scope_started = true;
                this->scope_started = true;
                this->scope_count += 1;
                vector<CommandExpression *> loop_ce;
                while (is_scope_started != false) {
                    loop_ce.push_back(CommandCreator(parameters));
                    parameters.erase(parameters.begin());
                    if (loop_ce.back() == nullptr) {
                        is_scope_started = false;
                        parameters.erase(parameters.begin(), parameters.begin() + this->expression_count + 1);
                    }
                }
                this->scope_count -= 1;
                param.pop_back();
                string cmd_condition_name = param.front();
                string condition;
                param.erase(param.begin());
                while (param.size() != 0) {
                    condition += param.front();
                    param.erase(param.begin());
                }
                loop_ce.pop_back();
                this->expression_count = static_cast<int>(loop_ce.size());
                if (cmd_condition_name == "while") {
                    ce = new CommandExpression(new LoopCommand(loop_ce, condition));
                    this->cmd_expressions.push_back(ce);
                } else {
                    ce = new CommandExpression(new LoopCommand(loop_ce, condition));
                    this->cmd_expressions.push_back(ce);
                }
                if (this->scope_count == 0) {
                    data.setSimulatorData(cmd_condition_name, ce);
                    continue;
                } else {
                    return ce;
                }
            }
            case PRINT: {
                ce = new CommandExpression(new PrintCommand(param[1]));
                data.setSimulatorData(param[0], ce);
                return ce;
            }
            case SLEEP: {
                ce = new CommandExpression(new Sleep(param[1]));
                data.setSimulatorData(param[0], ce);
                return ce;
            }
            case INIT: {
                ce = new CommandExpression(new Assign(param));
                //ce->calculate();
                if (this->scope_started == true) {
                    return ce;
                } else {
                    data.setSimulatorData(param[0], ce);
                }
                break;
            }
        }
    }
}

void Interpreter::run() {
    // execute the commands
    for (CommandExpression* cmd : this->cmd_expressions) {
        cmd->calculate();
    }
}

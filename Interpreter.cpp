
#include "Interpreter.h"


#define CMD_SPLIT "#"
#define CMD_PARAMETER "|"
#define SIM_INPUT_SPLIT ","
#define SCOPE_CLOSE "}"
#define OPEN_CLOSE "{"
#define FILE_SPACE " "
#define FIRST_CELL 0

extern Data data;

/**
 * Ctor.
 */
Interpreter::Interpreter() {
    this->scope_count = 0;
    this->scope_open = false;
}

/**
 * Ctor.
 * @param simulator_data
 */
Interpreter::Interpreter(string simulator_data) {
    this->scope_count = 0;
    this->scope_open = false;
    DataParser(simulator_data, CMD_SPLIT);
    CommandCreator(this->victor);
}

/**
 * Parser the data
 * @param strData
 * @param strSpliter
 */
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
            cmdParameters = lineData.substr(0, pos);
            cmdData.push_back(cmdParameters);
            lineData.erase(0, pos + 1);
        }
        cmdData.push_back(lineData);
        this->victor.push_back(cmdData);
    }
}

/**
 * Collect the run_expressions vector and adding the relevant data to
 * SimulatorData map
 * @param name
 * @param cmd_exp
 */
void Interpreter::runDataMap(string &name, CommandExpression *cmd_exp) {
    data.setSimulatorData(name, cmd_exp);
    this->run_expressions.push_back(cmd_exp);
}

/**
 * This function responsible to crate the right command and insert the data of them
 * to the right map in Data class
 * @param parameters
 * @return
 */
CommandExpression *Interpreter::CommandCreator(vector<vector<string>> parameters) {
    /*
     * creates the commands as far as parameters isn't empty
     */
    while (!parameters.empty()) {
        vector<string> param;
        //gets the first string for it's command creation
        param = parameters.at(FIRST_CELL);
        parameters.erase(parameters.begin());
        simulatorCommand commandClass;
        //checks the relevant case for the command creation
        if (CMD_DICTIONARY.find(param[FIRST_CELL]) != CMD_DICTIONARY.end()) {
            commandClass = CMD_DICTIONARY[param[FIRST_CELL]];
        }
            //the case the is no creation left during the recursion
        else if (param[FIRST_CELL] == SCOPE_CLOSE) {
            return 0;
        } else {
            commandClass = INIT;
        }
        CommandExpression *ce;
        /*
         * creates the command according to the command's constructor
         * each one creates command and wraps him with Expression command - CommandExpression
         * in addition, each one of the cases know whether return or break according to
         * the 'scope_open' member
         */
        switch (commandClass) {
            //open data server command
            case OPEN_DATA_SERVER: {
                OpenDataServer *ods = new OpenDataServer(param[1], param[2]);
                ce = new CommandExpression(ods);
                data.addToDelete(ce);
                data.addCmdToDel(ods);
                if (this->scope_open) {
                    return ce;
                }
                runDataMap(param[FIRST_CELL], ce);
                break;
            }
                //connect command
            case CONNECT: {
                Connect *connect = new Connect(param[1], param[2]);
                ce = new CommandExpression(connect);
                data.addToDelete(ce);
                data.addCmdToDel(connect);
                if (this->scope_open) {
                    return ce;
                }
                runDataMap(param[FIRST_CELL], ce);
                break;
            }
            case VAR: {
                DefineVarCommand define_var_command(param);
                if (param[FIRST_CELL] != "var") {
                    data.setSimulatorData(param[0] + param[1] + param[2], ce);
                    return ce;
                } else {
                    break;
                }
            }
                /*
                 * the case creates the conditional parser command:
                 * this case calls the "CommandCreator" function each time the first word
                 * in the string if while or if. This case manages the command's vector as well
                 * according to the loop_counter command.
                 */
            case CONDITIONAL: {
                bool is_scope_started = true;
                this->scope_open = true;
                this->scope_count += 1;
                vector<CommandExpression *> loop_ce;
                /*
                 * The main while which counts and calls CommandCreator function
                 * in addition, it collects the command expressions in to list in order to
                 * assign the list to the condition parser class
                 */
                while (is_scope_started) {
                    //collect the command expressions of the correct conditional
                    loop_ce.push_back(CommandCreator(parameters));
                    //check which kind of earse should be done
                    if (parameters[FIRST_CELL][FIRST_CELL] == "while"
                        || parameters[FIRST_CELL][FIRST_CELL] == "if") {
                        //erase the number of the last conditional's command list
                        parameters.erase(parameters.begin(),
                                         parameters.begin() + this->expression_count + 2);
                        this->expression_count = 0;
                    } else {
                        //erase the first vector
                        parameters.erase(parameters.begin());
                    }
                    if (loop_ce.back() == nullptr) {
                        is_scope_started = false;
                    }
                }
                //sets up the conditional parameters
                this->scope_count -= 1;
                string cmd_condition_name = param.front();
                string condition;
                param.erase(param.begin());
                while (param.size() != 0) {
                    condition += param.front();
                    param.erase(param.begin());
                }
                int pos;
                if ((pos = condition.find(OPEN_CLOSE)) != string::npos) {
                    condition.erase(pos, 1);
                }
                //erase the 'null' vector
                loop_ce.pop_back();
                this->expression_count = static_cast<int>(loop_ce.size());
                //creates the correct CommandExpression
                if (cmd_condition_name == "while") {
                    LoopCommand *lc = new LoopCommand(loop_ce, condition);
                    ce = new CommandExpression(lc);
                    data.addToDelete(ce);
                    data.addCmdToDel(lc);
                } else {
                    IfCommand *ic = new IfCommand(loop_ce, condition);
                    ce = new CommandExpression(ic);
                    data.addToDelete(ce);
                    data.addCmdToDel(ic);
                }
                if (this->scope_count == 0) {
                    runDataMap(cmd_condition_name, ce);
                    this->scope_open = false;
                    continue;
                } else {
                    return ce;
                }
            }
                //Print command
            case PRINT: {
                PrintCommand *pc = new PrintCommand(param[1]);
                ce = new CommandExpression(pc);
                data.addToDelete(ce);
                data.addCmdToDel(pc);
                if (this->scope_open) {
                    return ce;
                }
                runDataMap(param[FIRST_CELL], ce);
                break;
            }
                //Sleep command
            case SLEEP: {
                Sleep *sl = new Sleep(param[1]);
                ce = new CommandExpression(sl);
                data.addToDelete(ce);
                data.addCmdToDel(sl);
                if (this->scope_open) {
                    return ce;
                }
                runDataMap(param[FIRST_CELL], ce);
                break;
            }
                //Assign command
            case INIT: {
                string val_exp;
                string val = param[FIRST_CELL];
                param.erase(param.begin());
                for (int i = 1; i < param.size(); i++) {
                    val_exp += param[i];
                }
                Assign *assign = new Assign(val, val_exp);
                ce = new CommandExpression(assign);
                data.addToDelete(ce);
                data.addCmdToDel(assign);
                if (this->scope_open) {
                    return ce;
                }
                runDataMap(param[FIRST_CELL], ce);
                break;
            }
        }
    }
}

/**
 * the main run of the maps
 */
void Interpreter::run() {
    // execute the commands
    for (CommandExpression *cmd : this->run_expressions) {
        cmd->calculate();
    }
}
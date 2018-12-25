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

#define CMD_SPLIT "#"
#define CMD_PARAMETER "|"
#define SIM_INPUT_SPLIT ","
#define FILE_SPACE " "

/**
 * Interpreter's Constructor
 */
Interpreter::Interpreter(){
    isFileLoaded = false;//TODO:add the flight user data from the Cin?
}
/**
 * Interpreter's Constructor
 * @param userFileName - the name of the user's flights commands
 */
Interpreter::Interpreter(string userFileName){
    this->scope_count=0;
    isFileLoaded = false;//TODO:check if necessary
    this->scope_started = false;
    this->flightUserInput = fileReader(&simulatorUserFile, this->isFileLoaded, userFileName);
    cout<<flightUserInput<<endl;//TODO:for debuging reasons
    DataParser(this->flightUserInput,CMD_SPLIT);
    CommandCreator(this->victor);
}
/**
 * Function Name: FileReader
 * @param dataFile - A pointer to the user's flight commands file
 * @param isLoaded - TODO:check if necessary
 * @param fileName - The user's flight commands file name as.txt. sends via the register
 * @return all the commands as one string splited by the sign '|'
 */
string Interpreter::fileReader(fstream *dataFile, bool isLoaded, string& fileName) {
    string line, commandsFileLine;
    dataFile->open(fileName);
    //checks if the file has been opened successfully
    if (!dataFile->is_open()) {
        throw "ERROR: CAN'T OPEN THE FILE";//TODO:check try and catch
    }
        //run the lexer functions as far as there is a non empty line
        while (getline(*dataFile, line)) {
            commandsFileLine += lexer(line, FILE_SPACE);
            //enterObjData(lineFilds, section);//TODO:check if needed for the map
        }
        cout<<commandsFileLine<<endl;//TODO:for debuging reasons
        //*isLoaded = true;TODO:check if necessary
    dataFile->close();
    return(commandsFileLine);
}
/**
 * Function Name: lexer
 * @param line - the line for lexing
 * @param split - the split sign between the commands
 * @return - a string that ready to be add to all commands string (commandsFileLine)
 */
//template <class T>TODO:check generics
string Interpreter::lexer(string line, string split) {
    size_t pos = 0;
    string dataTaken;
    //run the loop as far as it has space bars
    while ((pos = line.find(split)) != string::npos) {
        dataTaken += line.substr(0, pos) + CMD_PARAMETER;
        line.erase(0, pos + split.length());
    }
    //adds the last string left in the line
    //deletes the number in the begging of the line
    dataTaken += line.substr(0, pos) + CMD_SPLIT;
    pos = dataTaken.find('.') + 1;
    dataTaken = dataTaken.substr(pos,dataTaken.length());//earse the number from the beginning
    return dataTaken;
}

vector<double> Interpreter::simLexer(string line, string split) {
    size_t pos = 0;
    vector<double> dataTaken;
    //run the loop as far as it has space bars
    while ((pos = line.find(split)) != string::npos) {
        //dataTaken += line.substr(0, pos) + CMD_PARAMETER;
        dataTaken.push_back(stod(line.substr(0, pos) + SIM_INPUT_SPLIT));
        line.erase(0, pos + split.length());
    }
    //adds the last string left in the line
    //deletes the number in the begging of the line
//    dataTaken += line.substr(0, pos) + CMD_SPLIT;
//    pos = dataTaken.find('.') + 1;
    //dataTaken = dataTaken.substr(pos,dataTaken.length());//earse the number from the beginning
    dataTaken.push_back(stod(line.substr(0, pos) + SIM_INPUT_SPLIT));
    return dataTaken;
}

void Interpreter::DataParser(string strData, string strSpliter) {
    vector<string> cmdData;
    string lineData = strData;
    size_t pos = 0;
    string cmdParameters;
    if (strSpliter == CMD_SPLIT) {
        while ((pos = lineData.find(strSpliter)) != string::npos) {
            cmdParameters = lineData.substr(0, pos);
            DataParser(cmdParameters,CMD_PARAMETER);
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
        //DataCreator(cmdData);
    }
}

CommandExpression* Interpreter::CommandCreator(vector<vector<string>> parameters) {
    while (!parameters.empty()){//parameter not empty
        vector<string> param;
        param = parameters.at(0);
        //parameters.pop_back();
        parameters.erase(parameters.begin());
        simulatorCommand commandClass = VAR;
        if (find(param.begin(), param.end(),"=")!=param.end()){
            commandClass = INIT;
            if (find(param.begin(), param.end(),"var")!=param.end()){
                commandClass = VAR;
            }
        }
        else if(CMD_DICTIONARY.find(param[0]) != CMD_DICTIONARY.end()){
            commandClass = CMD_DICTIONARY[param[0]];//TODO: add the switch case issues to function
        } else {
            if(param[0]=="}"){
                return 0;
            }
            commandClass = CMD_DICTIONARY["="];
            if(param[0]=="while" || param[0]=="}") {//temporary condition
                commandClass = CMD_DICTIONARY["temp"];//temporary condition
            }
        }
        CommandExpression* ce;
        switch(commandClass)
        {
            case OPEN_DATA_SERVER: {
                ce = new CommandExpression(new OpenDataServer(param[1],param[2]));//TODO: add calculate
                ce->calculate();
                data.setSimData(param[0],ce);
                //return ce;
                break;
            }
            case CONNECT: {
                ce = new CommandExpression(new Connect(param[1],param[2]));
                //ce->calculate();
                data.setSimData(param[0],ce);
                //return ce;
                break;
            }
            case VAR: {
                ce = new CommandExpression(new DefineVarCommand(param, &data));
                //ce->calculate();
                //return ce;
                break;
            }
            case CONDITIONAL: {
                bool is_scope_started = true;
                this->scope_started=true;
                vector<CommandExpression*> loop_ce;
                //list<CommandExpression*> loop_ce;
                while (is_scope_started!=false){
                    loop_ce.push_back(CommandCreator(parameters));
                    parameters.erase(parameters.begin());
                    if(loop_ce.back()== nullptr){
                        is_scope_started=false;
                    }
                }
                loop_ce.pop_back();
                string str="check";
                //vector<CommandExpression*> loop_check = loop_ce;
                ce = new CommandExpression(new LoopCommand(loop_ce,str, &data));
                //ce->calculate();
            if(!this->scope_started){
            }
            //data.setSimulatorData(parameters);
                break;
            }
////            case PRINT: {
////                data.setSimulatorData(parameters);
////                break;
////            }
//            case SLEEP: {
//                data.setSimulatorData(parameters);
//                break;
//            }
            case INIT: {
                ce = new CommandExpression(new Assign(param));
                ce->calculate();
                if(this->scope_started==true){
                    return ce;
                }
                //data.setPlaneData(parameters);
                break;
            }
//            default:
//                data.setSimulatorData(parameters);
        }
    }
}
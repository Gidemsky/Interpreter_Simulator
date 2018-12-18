//
// Created by gideon on 14/12/18.
//

#include "Interpreter.h"

#define CMD_SPLIT "#"
#define CMD_PARAMETER "|"
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
    isFileLoaded = false;//TODO:check if necessary
    this->flightUserInput = fileReader(&simulatorUserFile, this->isFileLoaded, userFileName);
    cout<<flightUserInput<<endl;//TODO:for debuging reasons
    DataParser(this->flightUserInput,CMD_SPLIT);
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
string Interpreter::lexer(string line, string split) {
    size_t pos = 0;
    string dataTaken;
    //run the loop as far as it has space bars
    while ((pos = line.find(split)) != string::npos) {
        dataTaken += line.substr(0, pos) + CMD_PARAMETER;
        line.erase(0, pos + split.length());
    }
    //adds the last string left in the line
    dataTaken += line.substr(0, pos) + CMD_SPLIT;
    pos = dataTaken.find(".") + 1;
    dataTaken = dataTaken.substr(pos,dataTaken.length());//earse the number from the beginning
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
            //cmdData.push_back(cmdParameters);
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
        if(cmdData[0]=="var"){
            data.setPlaneData(cmdData);
        } else {
            data.setSimulatorData(cmdData);
        }
    }
}

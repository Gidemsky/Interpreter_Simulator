//
// Created by gideon on 26/12/18.
//

#include "Lexer.h"
#include <algorithm>
#include <list>
#include "Interpreter.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "Connect.h"
#include "DefineVarCommand.h"


#define SIM_INPUT_SPLIT ","
#define FILE_SPACE " "
#define CMD_SPLIT "#"
#define CMD_PARAMETER "|"

#include "Interpreter.h"
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "Connect.h"
#include "DefineVarCommand.h"
#include "Assign.h"
#include "LoopCommand.h"
#include "Sleep.h"

Lexer::Lexer(){}
Lexer::Lexer(string userFileName) {
    //isFileLoaded = false;//TODO:check if necessary
    //this->scope_started = false;
    this->flightUserInput = fileReader(&simulatorUserFile, this->isFileLoaded, userFileName);
    cout<<flightUserInput<<endl;//TODO:for debuging reasons
}

/**
 * Function Name: lexer
 * @param line - the line for lexing
 * @param split - the split sign between the commands
 * @return - a string that ready to be add to all commands string (commandsFileLine)
 */
//template <class T>TODO:check generics
string Lexer::lexer(string line, string split) {
    size_t pos = 0;
    string dataTaken, final_line;
    bool is_converted = false;
    //run the loop as far as it has space bars
    while ((pos = line.find(split)) != string::npos) {
        dataTaken += line.substr(0, pos) + CMD_PARAMETER;
        line.erase(0, pos + split.length());
    }
    //adds the last string left in the line
    //deletes the number in the begging of the line
    dataTaken += line.substr(0, pos) + CMD_SPLIT;

    /*
     * this block responsible to locolize the (-) sign and rearange
     * the string for correct shunting yard progress
     */
    while ((pos= dataTaken.find('-')) != string::npos){
        if(dataTaken.at(pos-1)=='*' || dataTaken.at(pos-1)=='|'
        || dataTaken.at(pos-1)=='+' || dataTaken.at(pos-1)=='/'
        || (dataTaken.at(pos-1)==' ' &&
        (dataTaken.at(pos-1)!=')' || dataTaken.at(pos-1)!='('))){
                dataTaken.insert(pos,"(0");
                final_line += dataTaken.substr(0,pos+3);
                dataTaken.erase(0, pos + 3);
                //adding the rest string to the rearanged one
                while((dataTaken.at(0)>='0' && dataTaken.at(0)<='9')
                || dataTaken.at(0)=='.'){
                    final_line += dataTaken.substr(0,1);
                    dataTaken.erase(0, 1);
                }
                final_line.insert(final_line.size(),")");
                is_converted=true;
        } else {
            //finish the loop
            break;
        }
    }
    //return the converted string
    if(is_converted){
        final_line += dataTaken;
        return final_line;
    }
//    pos = dataTaken.find('.') + 1;
//    dataTaken = dataTaken.substr(pos,dataTaken.length());//earse the number from the beginning
    return dataTaken;
}

/**
 * Function Name: FileReader
 * @param dataFile - A pointer to the user's flight commands file
 * @param isLoaded - TODO:check if necessary
 * @param fileName - The user's flight commands file name as.txt. sends via the register
 * @return all the commands as one string splited by the sign '|'
 */
string Lexer::fileReader(fstream *dataFile, bool isLoaded, string& fileName) {
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

vector<double> Lexer::simLexer(string line, string split) {//TODO:check if generic is possiable
    size_t pos = 0;
    vector<double> dataTaken;
    //run the loop as far as it has space bars
    while ((pos = line.find(split)) != string::npos) {
        //dataTaken += line.substr(0, pos) + CMD_PARAMETER;
        dataTaken.push_back(stod(line.substr(0, pos) + SIM_INPUT_SPLIT));
        line.erase(0, pos + split.length());
    }
    dataTaken.push_back(stod(line.substr(0, pos) + SIM_INPUT_SPLIT));
    return dataTaken;
}

const string &Lexer::getFlightUserInput() const {
    return flightUserInput;
}

//string Lexer::fileReader(fstream *dataFile, bool isLoaded, string &userFileName) {
//
//    return std::__cxx11::string();
//}

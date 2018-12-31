
#include "Interpreter.h"
#include "OpenDataServer.h"
#include "Lexer.h"
#include "Data.h"

#define FILE_NAME_INDEX 1

Data data;

/**
 * Run the program
 * @param file_name is the file name to read from.
 */
void run(string file_name) {
    Lexer *lexer = new Lexer(file_name);
    string lexer_data = lexer->getFlightUserInput();
    Interpreter *parser = new Interpreter(lexer_data);
    try {
        parser->run();
        // delete memory
        delete parser;
        delete lexer;
    } catch (string msg) {
        cout << msg << endl;
    }
}

/**
 * Main
 * @param argc
 * @param argv includes the file name of the script.
 */
int main(int argc, char *argv[]) {
    // notify that we start to run the program
    data.setRunning(true);
    run(argv[FILE_NAME_INDEX]);
    data.setRunning(false);
    // delete allocated memory from the data
    data.deleteMemory();
    // close the pthread
    pthread_exit(nullptr);
}
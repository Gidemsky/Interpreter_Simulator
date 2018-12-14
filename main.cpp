#include <iostream>

#include "Interpreter.h"

int main() {
    std::cout << "DBD LEGEND" << std::endl;
    Interpreter* check = new Interpreter("CommandTestFile.txt");
    return 0;
}
#include <iostream>

#include "Interpreter.h"
#include "Expression.h"
#include "Plus.h"
#include "Number.h"
#include "Neg.h"
#include "OpenDataServer.h"
#include <netinet/in.h>
#include "Condition.h"
#include "algorithm"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Data.h"
Data data;//Global Class

//int mainSave() {
//
////    ShuntingYard* sy = new ShuntingYard();
////
////    Expression* e = sy->createExpression("300-2");
////
////    cout << e->calculate() << endl;
//
//    Data* data = new Data();
//    Condition* c = new Condition("300 - 200 <= 100", data);
//
//
//    if (c->evaluate() == true) {
//        cout << "DBD LEGEND" << endl;
//    }
//
//    return 0;
//}
//
//int mainSave2() {
//    Expression *exp = new Plus(new Neg(new Number(3.0)),
//                               new Number(5.0));
////    void* thread_func(void* arg) {
////        int server_fd, new_socket, valread;
////        struct sockaddr_in address;
////        server_fd = socket(AF_INET, SOCK_STREAM, 0);
////        address.sin_family = AF_INET;
////        address.sin_addr.s_addr = INADDR_ANY;
////        address.sin_port = htons(5400);
////        bind(server_fd, (struct sockaddr *) &address, sizeof(address));
////        listen(server_fd, 5);
////
////        pthread_t trid;
////        pthread_create(&trid, nullptr, thread_func, nullptr);
////    }
//
//    string port = "5400";
//    string hrz = "10";
//    OpenDataServer c = OpenDataServer(port, hrz);
//    c.execute();
//}
//
//
//int mainSave3() {
//
//    Data *data = new Data();
//    data->initializePaths();
//    vector<string> paths = data->getPaths();
//
//    for (string str : paths) {
//        cout << str << endl;
//    }
//
//    data->initializePathValues();
//    int a = 3;
//
//    return 0;
//}
#include "Connect.h"

int main() {
    Lexer* lexer = new Lexer("CommandTestFile.txt");
    string lexer_data = lexer->getFlightUserInput();
    Interpreter* parser = new Interpreter(lexer_data);
    parser->Run();
//    string port = "5400";
//    string hrz = "10";
//    OpenDataServer c = OpenDataServer(port, hrz);
//    c.execute();
//    Connect ce("127.0.0.1", "5402");
//    ce.execute();
    pthread_exit(nullptr);
}
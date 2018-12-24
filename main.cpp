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

int main() {

//    ShuntingYard* sy = new ShuntingYard();
//
//    Expression* e = sy->createExpression("300-2");
//
//    cout << e->calculate() << endl;

    Data* data = new Data();
    Condition* c = new Condition("300 - 200 <= 100", data);


    if (c->evaluate() == true) {
        cout << "DBD LEGEND" << endl;
    }

    return 0;
}

int saveMain() {
    std::cout << "DBD LEGEND" << std::endl;
    //Interpreter* check = new Interpreter("CommandTestFile.txt");
    Expression *exp = new Plus(new Neg(new Number(3.0)),
                               new Number(5.0));
//    void* thread_func(void* arg)
//    {
//        int server_fd, new_socket, valread;
//        struct sockaddr_in address;
//        server_fd = socket(AF_INET, SOCK_STREAM, 0);
//        address.sin_family = AF_INET;
//        address.sin_addr.s_addr = INADDR_ANY;
//        address.sin_port = htons(5400);
//        bind(server_fd, (struct sockaddr *)&address, sizeof(address));
//        listen(server_fd, 5);
//    }
//        pthread_t trid;
//        pthread_create(&trid, nullptr, thread_func, nullptr);

    //std::cout << exp->calculate() << std::endl;
//    return 0;
//    cout << evaluate("10 + 2 * 6") << "\n";
//    cout << evaluate("100 * 2 + 12") << "\n";
//    cout << evaluate("100 * ( 2 + 12 )") << "\n";
//    cout << evaluate("100 * ( 2 + 12 ) / 14");
//    string port = "5400";
//    string hrz = "10";
//    OpenDataServer c = OpenDataServer(port, hrz);
//    c.execute();
}
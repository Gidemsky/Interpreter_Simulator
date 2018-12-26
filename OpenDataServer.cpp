//
// Created by gideon on 18/12/18.
//

#include <utility>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "OpenDataServer.h"
#include "Data.h"
extern Data data;

double OpenDataServer::getPort() const {
    return port;
}

void OpenDataServer::setPort(double port) {
    OpenDataServer::port = port;
}

double OpenDataServer::getHz() const {
    return hz;
}

void OpenDataServer::setHz(double hz) {
    OpenDataServer::hz = hz;
}

double OpenDataServer::execute() {
    while (true) {
        int server_fd, new_socket, valread;
        char buffer[5000];
        struct sockaddr_in address{};//address
        int addrlen = sizeof(address);
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(5400);
        bind(server_fd, (struct sockaddr *) &address, sizeof(address));
        listen(server_fd, 5);

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        data.initializePaths();
        data.initializePathValues();

        //TODO: open pthread

        while(true) {
            ssize_t erez = read(new_socket, buffer, 5000);
            data.setPathValues(buffer);
            printf("%s\n", buffer);


        }
    }
}
//
OpenDataServer::OpenDataServer(string port, string hz){
    ShuntingYard shuntingYard;
    this->port = shuntingYard.createExpression(port)->calculate();
    this->hz = shuntingYard.createExpression(hz)->calculate();
   // this->data = data;
}

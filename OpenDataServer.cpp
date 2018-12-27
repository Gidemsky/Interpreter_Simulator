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
#include "pthread.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

extern Data data;

struct Parameters {
    int port;
    int hz;
    int socket;
};

typedef struct Parameters Parameters;

void* OpenDataServer::readFromServer(void* params) {
    struct Parameters* p = (struct Parameters*) params;
    string buffer = "";
    char c;
    int n;


    while (true) {
        n = read(p->socket, &c, 1);
        if (n<0){
            perror("Error reading from socket.");
            exit(1);
        }
        while (c != '\n') {
            if (n < 0) {
                perror("Eroor reading from socket");
                exit(1);
            }
            buffer += c;
            n = read(p->socket, &c, 1);
        }

        buffer += '\n';
        data.setPathValues(buffer);
        cout << buffer << endl;
        buffer = "";
    }
}


double OpenDataServer::execute() {
    pthread_t pthread;
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    auto param = new Parameters{};
    param->socket = newsockfd;
    param->hz = 10;
    param->port = 5400;

    data.initializePaths();
    //data.initializePathValues();


    pthread_create(&pthread, nullptr, readFromServer, param);
}

//
OpenDataServer::OpenDataServer(string port, string hz){
    ShuntingYard shuntingYard;
    this->port = shuntingYard.createExpression(port)->calculate();
    this->hz = shuntingYard.createExpression(hz)->calculate();
}

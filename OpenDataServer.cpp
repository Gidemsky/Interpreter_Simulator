
#include "OpenDataServer.h"
#include <utility>
#include <iostream>
#include <sys/socket.h>
#include "Data.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

extern Data data;

struct Parameters {
    int port;
    int hz;
    int socket;
};

typedef struct Parameters Parameters;

pthread_mutex_t mutex;

void *OpenDataServer::readFromServer(void *pparams) {
    auto *p = (struct Parameters *) pparams;
    Parameters params;
    params.hz = p->hz;
    params.port = p->port;
    params.socket = p->socket;
    delete p;
    string buffer;
    char c;
    ssize_t n = 0;

    while (true) {
        do {
            n = read(params.socket, &c, 1);
            buffer += c;
            if (n < 0) {
                perror("Eroor reading from socket");
                exit(1);
            }
        } while (c != '\n');
        pthread_mutex_lock(&mutex);
        data.setPathValues(buffer);
        pthread_mutex_unlock(&mutex);
        buffer = "";
    }
}

double OpenDataServer::execute() {
    pthread_t pthread;
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr{}, cli_addr{};
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    // A client is accepted
    auto param = new Parameters{};
    param->socket = newsockfd;
    param->hz = hz;
    param->port = port;
    pthread_create(&pthread, nullptr, readFromServer, param);
}

OpenDataServer::OpenDataServer(string port, string hz) {
    ShuntingYard shuntingYard;
    this->port = static_cast<unsigned short>(shuntingYard.createExpression(port)->calculate());
    this->hz = static_cast<short>(shuntingYard.createExpression(hz)->calculate());
    data.initializePaths();
    data.initializePathValues();
}
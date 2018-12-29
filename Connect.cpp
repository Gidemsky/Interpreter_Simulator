//
// Created by gideon on 18/12/18.
//

#include "Connect.h"

struct Parameters {
    int port;
    string ip;
};

typedef struct Parameters Parameters;

pthread_mutex_t mutex2;

Connect::Connect(string ip_address, string port) {
    ShuntingYard shuntingYard;
    this->ip_address = ip_address;
    this->port = shuntingYard.createExpression(port)->calculate();
}

void *Connect::runClient(void *args) {
    auto *p = (struct Parameters *) args;
    Parameters params;
    int port = p->port;
    string ip = p->ip;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    string buffer;

    portno = port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    const char *x = ip.c_str();
    server = gethostbyname(x);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (::connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    //Now ask for a message from the user, this message
    //will be read by server
    //if there is new data
    while (true) {
        pthread_mutex_lock(&mutex2);

        // pthread_mutex_lock(&mutex);

        buffer = "set /controls/flight/rudder -1 \r\n";
        /* Send message to the server */
        const char *chr = buffer.c_str();
        n = write(sockfd, chr, strlen(chr));
        cout << buffer << endl;
        // data.setIsNewData(false);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
            // data.clearBind();

        }

        pthread_mutex_unlock(&mutex2);

    }
    cout << buffer;
    close(sockfd);
    exit(0);
    return 0;
}


double Connect::execute() {
    pthread_t pthread;
    int rc;
    Parameters *params = new Parameters();
    params->ip = this->ip_address;
    params->port = this->port;
    rc = pthread_create(&pthread, nullptr, runClient, params);

    if (rc) {
        cout << "Error! unable to create the thread";
        exit(1);
    }
}
//
// Created by gideon on 18/12/18.
//

#include "Connect.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

extern Data data;

struct Parameters {
    int port;
    int hz;
    int socket;
};

typedef struct Parameters Parameters;

Connect::Connect(string ip_address, string port) {
    ShuntingYard shuntingYard;
    this->ip_address=ip_address;
    this->port = shuntingYard.createExpression(port)->calculate();
}

double Connect::execute() {
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    char buffer[256];
//        if (sock < 0) {
//            perror("ERROR: can not open the file!");
//            exit(1);
//        }
//
//        struct sockaddr_in server;
//        server.sin_family = AF_INET;
//        if (inet_pton(AF_INET, ip_address.c_str(), &server.sin_addr) <= 0)  {
//            perror("Error on IP pton");
//        }
//        server.sin_port = htons(port);
//
//        size_t server_len = sizeof(sockaddr_in);
//
//        //std::cout << "debug" << endl;
//        memset(&server, 0, sizeof(server));
//
//        if (::connect(sock, (const sockaddr *) &server, server_len) < 0) {
//            perror("ERROR: can not connect to the host");
//            exit(1);
//        }
//int n=0;
//    while(true) {
//        cout << "set" << endl;
//        // sock is the socket to the server
//       // send(sock, "set /controls/flight/rudder 1\r\n", strlen("set /controls/flight/rudder 1\r\n"),0);
//       // usleep(30000);
//       string g="set /controls/flight/rudder 1\\r\\n";
//       strcpy(buffer,g.c_str());
//       n=write(sock,buffer,256);
//    }
    struct thread_data *my_thread_data;
    //my_thread_data = (struct thread_data *) c;
    int port = this->port;
    string ip = this->ip_address;
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
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    //Now ask for a message from the user, this message
    //will be read by server
    //if there is new data
    while (true) {
        //pthread_mutex_lock(&mutex);

            // pthread_mutex_lock(&mutex);

                buffer ="set /controls/flight/rudder 1\\r\\n";
                /* Send message to the server */
                const char *chr = buffer.c_str();
                n = write(sockfd, chr, strlen(chr));
                cout << buffer << endl;
               // data.setIsNewData(false);
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);


           // data.clearBind();
           // pthread_mutex_unlock(&mutex);
            // pthread_mutex_unlock(&mutex);
        }
    }
    cout << buffer;
    close(sockfd);
    exit(0);
    return 0;
}

//double ConnectCommand::doCommand() {
//    pthread_t thread;
//    int rc;
//    thread_data *my_thread_data = new thread_data();
//    my_thread_data->port = this->port;
//    my_thread_data->ip = this->ip;
//    rc = pthread_create(&thread, nullptr, runClient, my_thread_data);
//    if (rc) {
//        cout << "Error! unable to create thread";
//        exit(1);
//    }
//    close(sock);
//
//}

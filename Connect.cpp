//
// Created by gideon on 18/12/18.
//

#include "Connect.h"
#include <arpa/inet.h>

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
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)  {
        perror("ERROR: can not open the file!");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address.c_str());
    server.sin_port = htons(port);

    size_t server_len = sizeof(sockaddr_in);

    if (::connect(sock, (const sockaddr*)&server, server_len) < 0)    {
        perror("ERROR: can not connect to the");
        exit(1);
    }

    // sock is the socket to the server
    write(sock, "set /controls/flight/rudder 1\r\n", strlen("set /controls/flight/rudder 1\r\n"));

    close(sock);

}

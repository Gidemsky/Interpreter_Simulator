
#include "Connect.h"

struct Parameters {
    int port;
    string ip;
};

typedef struct Parameters Parameters;

/**
 * Ctor.
 * @param ip_address
 * @param port
 */
Connect::Connect(string ip_address, string port) {
    ShuntingYard shuntingYard;
    this->ip_address = ip_address;
    this->port = shuntingYard.createExpression(port)->calculate();
}

/**
 * Run the client.
 * @param args
 * @return
 */
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
    string path;
    // ask for data
    while (data.getRunning()) {
        // get the new data
        vector<pair<string, double>> plane_data = data.get_and_clear();
        unsigned long size = plane_data.size();
        for (int j = 0; j < size; ++j) {
            auto &i = plane_data[j];
            if (data.getBinds().count(i.first)) {
                path = data.getBind(i.first);
                buffer = "set " + path.substr(2, path.size() - 3) + " " + to_string(i.second) + " \r\n";
                /* Send message to the server */
                const char *chr = buffer.c_str();
                n = static_cast<int>(write(sockfd, chr, strlen(chr)));
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }
                // set the data in the symobl table
                data.setSymbolTable(i.first, i.second);
            }
        }
    }
    delete p;
    close(sockfd);
    exit(0);
}

/**
 * Execute the connect command.
 * @return
 */
double Connect::execute() {
    pthread_t pthread;
    int r;
    Parameters *params = new Parameters();
    params->ip = this->ip_address;
    params->port = this->port;
    r = pthread_create(&pthread, nullptr, runClient, params);
    if (r) {
        cout << "Error! unable to create the thread" << endl;
        exit(1);
    }
}
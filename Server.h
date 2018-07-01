#ifndef SANDBOX_SERVER_H
#define SANDBOX_SERVER_H


#include <string.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <regex>
#include "Connection.h"

using namespace std;

class Server {
    int sock, sock_listener;
    // struct sockaddr_in sock_addr;
    vector<Connection *> connections;

public:
    explicit Server(int port);
    void start();
    void removeConnection(Connection *connection);
};


#endif //SANDBOX_SERVER_H

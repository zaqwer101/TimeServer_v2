#ifndef SANDBOX_CONNECTION_H
#define SANDBOX_CONNECTION_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <regex>

using namespace std;
class Server;
class Connection {
    int sock;
    thread connection_thread;
    Server *server;
public:
    Connection(int sock, Server *server);
    void conection_handler();
};


#endif //SANDBOX_CONNECTION_H

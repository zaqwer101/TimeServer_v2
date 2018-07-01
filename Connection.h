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
#include "libcurlHandler.cpp"

using namespace std;
class Server;
class Connection {
    int id;
    int sock;
    thread connection_thread;
    Server *server;
    string exec(string command);
    string getTime(string timezone);

public:
    Connection(int sock, Server *server);
    void conection_handler();
    int getConnectionID();

};


#endif //SANDBOX_CONNECTION_H

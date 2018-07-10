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
#include <string.h>

using namespace std;

const int EXCEPTION_INCORRECT_TIMEZONE = -1;

class Server;
class Connection {
    int id;
    int sock;
    thread connection_thread;
    Server *server;
    string exec(string command);
    string getTime(string timezone);
    string parseTimezone(string html);
public:
    Connection(int sock, Server *server);
    void conection_handler();
    int getConnectionID();

};

#endif //SANDBOX_CONNECTION_H

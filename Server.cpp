#include "Server.h"

Server::Server(int port) {
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    sock_listener = socket(AF_INET, SOCK_STREAM, 0);
    bind(this->sock_listener, (struct sockaddr *) &sock_addr, sizeof(sock_addr));
}

void Server::start() {
    listen(this->sock_listener, 10);
    cout << "Начинаю" << endl;
    while(sock)
    {
        sock = accept(this->sock_listener, NULL, NULL);
        Connection *connection = new Connection(sock, this);
        this->connections.push_back(connection);
        cout << "Принял подключение, id = " << connection->getConnectionID() << "; sock = " << sock << endl;
    }
}

void Server::removeConnection(Connection *connection) {
    connections.erase(
            remove(connections.begin(), connections.end(), connection),
            connections.end()
            );
}

int Server::getConnectionsCount() {
    return connections.size();
}

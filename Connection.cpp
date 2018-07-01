#include "Connection.h"
#include "Server.h"


void Connection::conection_handler() {
    cout << "Поток начался" << endl;
    char buf[128];
    int bytes_read = 0;
    while (true) {
        memset(buf, 0, sizeof(buf)); // Очистка буфера
        bytes_read = recv(sock, buf, 1024, 0);
        if (bytes_read <= 0) break;
        string recv_string(buf);
        cout << recv_string;
        recv_string.erase(recv_string.find("\r\n"), 2); // Потому что в recv_string прилетают лишние служебные символы
        string send_string = "Принял: \"" + recv_string + "\"\n";
        send(sock, send_string.c_str(), send_string.size(), 0);
    }
    close(sock);
    this->server->removeConnection(this);
    cout << "Поток умер" << endl;
}

Connection::Connection(int sock, Server *server) {
    this->sock = sock;
    connection_thread = thread([this] { this->conection_handler(); });
    this->server = server;
    connection_thread.detach();
}
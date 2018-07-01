#include "Connection.h"
#include "Server.h"

void Connection::conection_handler() {
    char buf[128];
    int bytes_read = 0;
    while (true) {
        memset(buf, 0, sizeof(buf)); // Очистка буфера
        bytes_read = recv(sock, buf, 1024, 0);
        if (bytes_read <= 0) break;
        string recv_string(buf);
        cout << id << ": " << recv_string;
        recv_string.erase(recv_string.find("\r\n"), 2); // Потому что в recv_string прилетают лишние служебные символы

        string send_string = getTime(recv_string);

        send(sock, send_string.c_str(), send_string.size(), 0);
    }
    close(sock);
    this->server->removeConnection(this);
    cout << "Подключение " << this->id << " закрыто" << endl;
}
Connection::Connection(int sock, Server *server) {
    this->id = server->getConnectionsCount() + 1;
    this->sock = sock;
    connection_thread = thread([this] { this->conection_handler(); });
    this->server = server;
    connection_thread.detach();
}
int Connection::getConnectionID() {
    return this->id;
}
string Connection::exec(string command) {
    char buffer[128];
    string result = "";
    FILE *stream = popen(command.c_str(), "r");

    while (!feof(stream)) {
        if (fgets(buffer, 128, stream) != NULL)
            result += buffer;
    }
    pclose(stream); // Закрываем поток чтения
    return result;
}

string Connection::getTime(string tz) {
    string request_str = libcurlHandler::GET("https://time.is/en/" + timezone);

    string full_timezone = tz;
    return exec("LANG=en TZ=\"" + full_timezone + "\" date" );
}
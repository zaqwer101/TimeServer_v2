#include <iostream>
#include "Server.h"

int main() {
    Server *s = new Server(3228);
    s->start();
}
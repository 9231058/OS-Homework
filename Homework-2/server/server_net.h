#include "message.h"

#ifndef SERVER_NET_H
#define SERVER_NET_H

int server_port_number;

int send_message(Message* message, int socket_fd);

int recv_message(Message* message, int socket_fd);

#endif

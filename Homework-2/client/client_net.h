#include "message.h"

#ifndef CLIENT_NET_H
#define CLIENT_NET_H

char client_name[255];

char server_ip_address[255];

int server_port_number;

int buid_socket_fd();

void connect_socket(int socket_fd);

int send_message(Message* message);

#endif

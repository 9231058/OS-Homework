#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "client_net.h"
#include "message.h"

int socket_fd = -1;

int buid_socket_fd(){
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
}

void connect_socket(int socket_fd);

int send_message(Message* message);


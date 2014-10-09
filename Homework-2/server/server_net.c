#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "server_net.h"
#include "constants.h"
#include "error_functions.h"
#include "message.h"

int send_message(Message* message, int socket_fd){
	char buffer[MAX_BUFF];

	serialize_message(buffer, message);
	
	return send(socket_fd, buffer, strlen(buffer), 0);
}

int recv_message(Message* message, int socket_fd){
	char buffer[MAX_BUFF];

	FILE* socket_file = fdopen(socket_fd, "a+");

	fgets(buffer, MAX_BUFF, socket_file);

	deserialize_message(buffer, message);

	return strlen(buffer);
}


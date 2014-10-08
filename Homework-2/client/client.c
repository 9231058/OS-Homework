#include <stdio.h>
#include <string.h>

#include "command.h"
#include "client_net.h"
#include "error_functions.h"
#include "constants.h"

int main(int argc, char* argv[]){
	if(argc < 4){
		use_die("usage : client server_ip_address server_port_number client_name");
	}
	
	strcpy(client_name, argv[3]);
	strcpy(server_ip_address, argv[1]);
	server_port_number = atoi(argv[2]);

	while(1){
		printf("Client ChatHub:> ");
		
		char command[MAX_BUFF];
		fgets(command, MAX_BUFF, stdin);

		command_dispatcher(command);
	}
}

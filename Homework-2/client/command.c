#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "constants.h"
#include "message.h"
#include "client_net.h"

void command_dispatcher(const char* command){
	int group_id;
	char message_body[MAX_BUFF];

	char verb[MAX_BUFF];
	
	sscanf(command, "%s", verb);

	if(strcmp(verb, "join") == 0){
		sscanf(command, "%s %d", verb, &group_id);
		join(group_id);
	}else if(strcmp(verb, "send") == 0){
		sscanf(command, "%s %d %[^\n]%*c", verb, &group_id, message_body);
		send(group_id, message_body);
	}else if(strcmp(verb, "leave") == 0){	
		sscanf(command, "%s %d", verb, &group_id);
		leave(group_id);
	}else if(strcmp(verb, "show") == 0){
		char show_c;
		sscanf(command, "%s %c", verb, &show_c);
		show(show_c);
	}else if(strcmp(verb, "quit") == 0){
		quit();
	}
}

void join(int group_id){
	Message message;
	message.group_id = group_id;
	strcpy(message.arg, " ");
	strcpy(message.verb, "JOIN");

	send_message(&message);
}

void send(int group_id, const char* message_body){
	Message message;
	message.group_id = group_id;
	strcpy(message.arg, message_body);
	strcpy(message.verb, "SEND");

	send_message(&message);
}

void leave(int group_id){
	Message message;
	message.group_id = group_id;
	strcpy(message.arg, " ");
	strcpy(message.verb, "LEAVE");
	
	send_message(&message);
}

void show(char show_c){
	if(show_c == 'w'){
	}
	if(show_c == 'e'){
	}
	if(show_c == 'c'){
	}
}

void quit(){
	exit(0);
}




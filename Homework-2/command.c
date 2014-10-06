#include <stdio.h>
#include <stdlib.h>
#include "command.h"
#include "constants.h"

void command_dispatcher(const char* command){
	int group_id;
	char message_body[MAX_BUFF];

	char verb[MAX_BUFF];
	
	sscanf(command, "%s", verb);

	if(strcmp(verb, "join") == 0){
		sscanf(command, "%s %d", verb, &group_id);
		join(group_id);
	}else if(strcmp(verb, "send") == 0){
		sscanf(command, "%s %d %s", verb, &group_id, message_body);
		send(group_id, message_body);
	}else if(strcmp(verb, "quit") == 0){
		quit();
	}
}

void join(int group_id){

}

void send(int group_id, const char* message_body){

}

void leave(const char* arg);

void quit(){
	exit(0);
}




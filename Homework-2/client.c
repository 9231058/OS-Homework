#include <stdio.h>
#include <string.h>
#include "command.h"
#include "constants.h"

int main(int argc, char* argv[]){
	if(argc < 4){
		//TODO write error !!	
	}

	while(1){
		printf("Client ChatHub:> ");
		
		char command[MAX_BUFF];
		fgets(command, MAX_BUFF, stdin);

		command_dispatcher(command);
	}
}

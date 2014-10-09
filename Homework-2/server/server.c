#include <stdio.h>
#include <string.h>

#include "server_net.h"
#include "error_functions.h"
#include "constants.h"

int main(int argc, char* argv[]){

	printf("Gnomovision version 69, Copyright (C) 2014 Parham Alvani (parham.alvani@gmail.com)\n");
	printf("Gnomovision comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n");
	printf("This is free software, and you are welcome to redistribute it\n");
	printf("under certain conditions; type `show c' for details.\n");
	printf("\n");

	if(argc < 2){
		use_die("usage : server server_ip_address server_port_number");
	}
	
	server_port_number = atoi(argv[1]);
}

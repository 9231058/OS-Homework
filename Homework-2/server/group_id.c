#include "group_id.h"

void add(int socket_fd, GroupId* group_id){
	group_id->socket_fds[group_id->number] = socket_fd;
	group_id->number++;
}

int remove(int socket_fd, GroupId* group_id){
	int i = 0;
	for(i = 0; i < group_id->number; i++){
		if(group_id->socket_fds[i] == socket_fd){
			group_id->number--;
			if(group_id->number > 0){
				group_id->socket_fds[i] = group_id->socket_fds[group_id->number];
			}
			return socket_fd;
		}
	}
	return -1;
}



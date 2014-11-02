#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

sem_t reader_sem;
int shm_fd;

int main(int argc, char* argv[]){
	shm_fd = shm_open("/tmp", O_RDWR | O_CREAT, 0666);
	FILE* shm_file = fdopen(shm_fd, "r+");
	fprintf(shm_file, "HELLO_WORLD");

	if(fork() == 0){
		FILE* shm_file = fdopen(shm_fd, "r+");
		char buffer[255];
		fscanf(shm_file, "%s", buffer);
		printf("%s\n", buffer);
	}
}

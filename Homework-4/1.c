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
	shm_unlink("/tmp");
	shm_fd = shm_open("/tmp", O_RDWR | O_CREAT, 0666);
	FILE* shm_file = fdopen(shm_fd, "r+");
	fprintf(shm_file, "HELLO_WORLD\n");
	fflush(shm_file);
	printf("%d\n", shm_fd);

	int i = 0;
	for(i = 0; i < 10; i++){
		if(fork() == 0){
			printf("%d\n", shm_fd);
			FILE* shm_file = fdopen(shm_fd, "r+");
			char buffer[255];
			rewind(shm_file);
			fscanf(shm_file, "%s", buffer);
			printf("%s\n", buffer);
			exit(0);
		}
	}
	wait();
	close(shm_fd);
}

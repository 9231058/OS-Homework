#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

sem_t reader_sem;
int shm_fd;

int main(int argc, char* argv[]){
	shm_fd = shm_open("/tmp", O_RDWR | O_CREAT, 0666);
}

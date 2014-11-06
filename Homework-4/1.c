#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

#ifndef MAX
#define MAX 10
#endif

void reader();
void writer();
void die(const char* msg);

int main(int argc, char* argv[]){
	sem_t* read_bin_sem = sem_open("/read_bin_sem", O_CREAT | O_RDWR, 0666, 1);
	if(read_bin_sem == SEM_FAILED){
		die("sem_open()");
	}
	sem_t* rw_bin_sem = sem_open("/rw_bin_sem", O_CREAT | O_RDWR, 0666, 1);
	if(rw_bin_sem == SEM_FAILED){
		die("sem_open()");
	}


	int shm_fd;
	FILE* shm_file;

	shm_unlink("/buffer");	
	if(shm_fd = shm_open("/buffer", O_RDWR | O_CREAT, 0666) < 0){
		die("shm_open()");
	}
	shm_file = fdopen(shm_fd, "w");
	fprintf(shm_file, "%d\n", 0);
	fflush(shm_file);
	if(fclose(shm_file) < 0){
		die("fclose()");
	}
	
	shm_unlink("/reader_counter");
	if(shm_fd = shm_open("/reader_counter", O_RDWR | O_CREAT, 0666) < 0){
		die("shm_open()");
	}
	shm_file = fdopen(shm_fd, "w");
	fprintf(shm_file, "%d\n", 0);
	fflush(shm_file);
	if(fclose(shm_file) < 0){
		die("fclose()");
	}

	if(fork() == 0){
		writer();
	}

	int i = 0;
	for(i = 0; i < 10; i++){
		if(fork() == 0){
			reader();
		}
	}

	for(i = 0; i < 11; i++){
		int pid = 0;
		int status = 0;

		pid = wait(&status);

		printf("process %d is finished\n", pid);
	}
}

void reader(){
	sem_t* read_bin_sem = sem_open("/read_bin_sem", O_RDWR);
	if(read_bin_sem == SEM_FAILED){
		die("sem_open()");
	}
	sem_t* rw_bin_sem = sem_open("/rw_bin_sem", O_RDWR);
	if(rw_bin_sem == SEM_FAILED){
		die("sem_open()");
	}

	int shm_fd1;
	if(shm_fd1 = shm_open("/buffer", O_RDWR, 0666) < 0){
		die("shm_open()");
	}
	FILE* shm_file1 = fdopen(shm_fd1, "r");
	
	int shm_fd2;
	FILE* shm_file2;
	int reader_counter = 0;
	int value = 0;
	while(1){
		if(value == MAX){
			fclose(shm_file1);
			exit(0);
		}

		sem_wait(read_bin_sem);	//first phase, first reader wait for writer
	
		fprintf(stderr, "Hello world\n");

		if(shm_fd2 = shm_open("/reader_counter", O_RDWR, 0666) < 0){
			die("shm_open()");
		}
		shm_file2 = fdopen(shm_fd2, "r+");
		fscanf(shm_file2, "%d", &reader_counter);
		rewind(shm_file2);

		reader_counter++;
		printf("reader counter is %d\n", reader_counter);
		
		fprintf(shm_file2, "%d\n", reader_counter);
		fflush(shm_file2);
		fclose(shm_file2);

		if(reader_counter == 1){
			sem_wait(rw_bin_sem);
		}
		
		sem_post(read_bin_sem);
	
		fscanf(shm_file1, "%d", &value);
		printf("The reader (%ld) reads the value %d\n", getpid(), value);

		sem_wait(read_bin_sem);

		if(shm_fd2 = shm_open("/reader_counter", O_RDWR, 0666) < 0){
			die("shm_open()");
		}
		shm_file2 = fdopen(shm_fd2, "r+");
		fscanf(shm_file2, "%d", &reader_counter);
		rewind(shm_file2);

		reader_counter--;
		
		fprintf(shm_file2, "%d\n", reader_counter);
		fflush(shm_file2);
		fclose(shm_file2);

		if(reader_counter == 0){
			sem_post(rw_bin_sem);
		}

		sem_post(read_bin_sem);
	}	
}

void writer(){	
	sem_t* rw_bin_sem = sem_open("/rw_bin_sem", O_RDWR);
	if(rw_bin_sem == SEM_FAILED){
		die("sem_open()");
	}

	int shm_fd;
	if(shm_fd = shm_open("/buffer", O_RDWR, 0666) < 0){
		die("shm_open()");
	}
	FILE* shm_file = fdopen(shm_fd, "r+");

	int value = 0;
	while(1){
		if(value == MAX){
			fclose(shm_file);
			exit(0);
		}
		
		sem_wait(rw_bin_sem);
		
		fscanf(shm_file, "%d", &value);
		printf("The writer (%ld) writes the value %d\n", getpid(), value);
		rewind(shm_file);
		value++;
		fprintf(shm_file, "%d\n", value);
		fflush(shm_file);

		sem_post(rw_bin_sem);
	}
}

void die(const char* msg){
	perror(msg);
	exit(1);
}

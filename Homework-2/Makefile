GCC = gcc
LINUX_LIB = -lpthread
RM = rm -f
TAR = tar

HW_NO  = 2

all:
	${MAKE} client server
	${MAKE} tar 
client:
	${GCC} -o client.o -c client.c
	${GCC} -o clinet client.o
server:
	${GCC} -o server.o -c server.c
	${GCC} -o server server.o ${LINUX_LIB}
tar:
	${RM} *.tgz
	${TAR} cvfz os_assigment${HW_NO}_group20.tgz *.c *.help *.txt Makefile
clean:
	${RM} *.o
	${RM} client
	${RM} server

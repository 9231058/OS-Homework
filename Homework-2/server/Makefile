GCC = gcc
RM = rm -f
TAR = tar

HW_NO  = 2

all:
	${MAKE} server
server:
	${GCC} -c *.c
	${GCC} -o server *.o
clean:
	${RM} *.o
	${RM} server

<<<<<<< HEAD
GCC = gcc -g
=======
GCC = gcc
>>>>>>> 364451d814b2fe74eee1cae74ad135d626460285
LINUX_LIB = -lpthread -lrt
RM = rm -f
TAR = tar

HW_NO  = 4

all:
	${MAKE} 1 
	${MAKE} tar
1:
	${GCC} -o 1.o -c 1.c
	${GCC} -o 1 1.o ${LINUX_LIB}
tar:
	${RM} *.tar.gz
	${TAR} cvfz os_assigment${HW_NO}_group20.tgz *.c Makefile
clean:
	${RM} *.o
	${RM} 1

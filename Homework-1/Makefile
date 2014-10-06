GCC = gcc
LINUX_LIB = -lrt
RM = rm -f
TAR = tar

HW_NO  = 1

all:
	${MAKE} 1 2
	${MAKE} tar
1:
	${GCC} -o 1.o -c 1.c
	${GCC} -o 1 1.o
2:
	${GCC} -o 2.o -c 2.c
	${GCC} -o 2 2.o ${LINUX_LIB}
tar:
	${RM} *.tar.gz
	${TAR} cvfz os_assigment${HW_NO}_group20.tgz *.c *.help *.txt Makefile
clean:
	${RM} *.o
	${RM} 1
	${RM} 2

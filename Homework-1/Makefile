GCC = gcc
LINUX_LIBRT = -lrt
RM = rm -f

all:
	${MAKE} 1 2
1:
	${GCC} -o 1.o -c 1.c
	${GCC} -o 1 1.o
2:
	${GCC} -o 2.o -c 2.c
	${GCC} -o 2 2.o ${LINUX_LIBRT}
clean:
	${RM} *.o
	${RM} 1
	${RM} 2

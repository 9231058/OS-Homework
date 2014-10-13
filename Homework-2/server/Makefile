GCC = gcc
RM = rm -f
TAR = tar
CP = cp

all:
	${MAKE} server
server:
	${GCC} -c *.c
	${GCC} -o ChatHub-C *.o
clean:
	${RM} *.o
	${RM} ChatHub-C
install:
	${MAKE} server
	${CP} ChatHub-C.sh /etc/init.d/ChatHub-C
	${CP} ChatHub-C /usr/sbin/

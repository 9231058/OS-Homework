OBJ=hdd.o main.o
CFLAGS=-Wall -std=c99
HDD: $(OBJ)
	gcc $(CFLAGS) -o HDD $(OBJ)
main.o: main.c hdd.h
	gcc $(CFLAGS) -c main.c
hdd.o: hdd.c hdd.h
	gcc $(CFLAGS) -c hdd.c

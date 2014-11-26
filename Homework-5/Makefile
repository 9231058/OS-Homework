OBJ=main.o logical.o page_table.o memory.o

1: ${OBJ}
	gcc -o 1 ${OBJ}

main.o: main.c logical.h page_table.h memory.h logical.o page_table.o memory.o
	gcc -std=c99 -c main.c
logical.o: logical.c logical.h
	gcc -c logical.c
page_table.o: page_table.c page_table.h
	gcc -c page_table.c
memory.o: memory.c memory.h
	gcc -c memory.c

OBJ=main.o logical.o page_table.o memory.o mmu.o

1: ${OBJ}
	gcc -o 1 ${OBJ}
	./memory.sh

main.o: main.c logical.h mmu.h page_table.h memory.h logical.o mmu.o page_table.h memory.o
	gcc -std=c99 -c main.c
logical.o: logical.c logical.h
	gcc -c logical.c
page_table.o: page_table.c page_table.h
	gcc -c page_table.c
memory.o: memory.c memory.h
	gcc -c memory.c
mmu.o: mmu.c mmu.h logical.h logical.o
	gcc -c mmu.c

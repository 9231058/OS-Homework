#include "page_table.h"
#include "logical.h"
#include <stdio.h>
#include <stdint.h>

#define MAX 1000*1000

int main(int argc, char* argv[]){
	FILE* logical_addrs = fopen("assignment5/addresses.txt", "r");
	uint32_t number;
	int index = 0;
	logical_addr addrs[MAX];
	while(fscanf(logical_addrs, "%u", &number) > 0){
		logical_addr_parser(number, &addrs[index]);
		printf("read base: %1x , offset: %1x\n", addrs[index].page_number , addrs[index].page_offset);
		index++;
	}
}

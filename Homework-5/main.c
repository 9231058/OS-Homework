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
		index++;
	}

	for(int i = 0; i < 256; i++){
		add_page_table_entry(i, i, 0x0);
	}
}

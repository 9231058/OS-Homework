#include <stdint.h>
#include "page_table.h"

static page_table_entry table[255];

void add_page_table_entry(uint8_t index, page_table_entry* entry){
	table[index] = *entry;
}
uint8_t get_base_addr(uint8_t index){
	if(table[index].vn = 1){
		return table[index].base;
	}else{
		handler(table[index].base);
		return table[index].base;
	}
}

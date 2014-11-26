#include <stdint.h>
#include "page_table.h"

static page_table_entry table[255];

void add_page_table_entry(uint8_t index, page_table_entry* entry){
	table[index] = *entry;
}
uint8_t get_base_addr(uint8_t index){
	return table[index].base;
}

#include <stdint.h>
#include "page_table.h"

static page_table_entry table[255];

void add_page_table_entry(uint8_t index, uint8_t base, uint8_t flag){
	page_table_entry entry;
	entry.base = base;
	entry.flag = flag;
	table[index] = entry;
}
uint8_t get_base_addr(uint8_t index){
	if((table[index].flag & 0x1) == 1){
		handler(table[index].base);
		table[index].flag |= 0x1; 
	}
	return table[index].base;
}

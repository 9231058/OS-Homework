#include "page_table.h"
#include <stdint.h>

static page_table_entry table[255];
static page_fault_handler handler;

void add_page_table_entry(uint8_t index, uint8_t base, uint8_t flag){
	table[index].base = base;
	table[index].flag = flag;
	table[index].access = 0;
}

uint8_t get_base_addr(uint8_t index){
	if((table[index].flag & 0x0) == 0){
		handler(&table[index].base, index);
		table[index].flag |= 0x1;
	}
	table[index].access++;
	return table[index].base;
}

void set_handler(page_fault_handler pf_handler){
	handler = pf_handler;
}

void invalid_page_table_entry(uint8_t index){
	table[index].flag ^= 0x1;
}

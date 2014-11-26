#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include <stdint.h>

// Page table entry structure
//  8               0
// |-----------------|
// | Physical  Base  |
// |     Address     |
// |-----------------|
//

typedef struct{
	uint8_t base;
} page_table_entry;

void add_page_table_entry(uint8_t index, page_table_entry* entry);
uint8_t get_bsae_addr(uint8_t index);

#endif

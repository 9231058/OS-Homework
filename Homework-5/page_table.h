#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include <stdint.h>

// Page table entry structure
// 16           8 7               0
// |-------------|-----------------|
// |   reserved  | Physical  Base  |
// |             |     Address     |
// |-------------|-----------------|
//
// * VN : Valid/Invalid
//

typedef struct{
	uint8_t base;
	uint8_t flag;
} __attribute__((packed)) page_table_entry;

// Page fault handler must set for handling page faults.
//
//
typedef void (*page_fault_handler)(uint8_t base);

void add_page_table_entry(uint8_t index, uint8_t base, uint8_t flag);
uint8_t get_base_addr(uint8_t index);
void set_handler(page_fault_handler pf_handler);

#endif

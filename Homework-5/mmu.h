#ifndef MMU_H
#define MMU_H

#include "logical.h"
#include <stdint.h>

// TLB entry structure
// 16          8 7          0
// |------------|------------|
// |    Frame   |    Page    |
// |    Index   |   Index    |
// |------------|------------|
//
//
typedef struct{
	uint8_t page_index;
	uint8_t frame_index;
}__attribute__((packed)) tlb_entry;

uint8_t l_to_p(const logical_addr* l_addr);

#endif

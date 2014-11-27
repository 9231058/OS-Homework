#ifndef MMU_H
#define MMU_H

#include "logical.h"
#include <stdint.h>

// TLB entry structure
// 32              16          8 7          0
// |---------------|------------|------------|
// |  Access       |    Frame   |    Page    |
// |         Times |    Index   |   Index    |
// |---------------|------------|------------|
//
//
typedef struct{
	uint8_t page_index;
	uint8_t frame_index;
	uint16_t access;
}__attribute__((packed)) tlb_entry;

uint8_t l_to_p(const logical_addr* l_addr, int* tlb_hit);

#endif

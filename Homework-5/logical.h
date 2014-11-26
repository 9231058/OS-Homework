#ifndef LOGICAL_H
#define LOGICAL_H

#include <stdint.h>

typedef struct{
	uint8_t page_number;
	uint8_t page_offset;
}logical_addr;

static uint16_t page_number_mask = 0xFF << 8;
static uint16_t page_offset_mask = 0xFF;

void logical_addr_parser(uint16_t i_addr, logical_addr* o_addr);

#endif

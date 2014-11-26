#ifndef LOGICAL_H
#define LOGICAL_H

#include <stdint.h>

typedef struct{
	int8_t page_number;
	int8_t page_offset;
}logical_addr;

static int16_t page_number_mask = 0xFF00;
static int16_t page_offset_mask = 0x00FF;

void logical_addr_parser(int16_t i_addr, logical_addr* o_addr);

#endif

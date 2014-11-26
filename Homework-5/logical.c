#include "logical.h"

void logical_addr_parser(uint16_t i_addr, logical_addr* o_addr){
	o_addr->page_number = (i_addr & page_number_mask) >> 8;
	o_addr->page_offset = i_addr & page_offset_mask;
}

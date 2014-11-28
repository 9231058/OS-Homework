// In The Name Of God
// ========================================
// * File Name : logical.c
// 
// * Creation Date : 28-11-2014
//
// * Last Modified : Fri 28 Nov 2014 08:26:00 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include "logical.h"

void logical_addr_parser(uint16_t i_addr, logical_addr* o_addr){
	o_addr->page_number = (i_addr & page_number_mask) >> 8;
	o_addr->page_offset = (i_addr & page_offset_mask);
}

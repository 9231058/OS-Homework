#include "mmu.h"
#include "logical.h"
#include "page_table.h"
#include <stdint.h>

static tlb_entry tlb[16];
static int last_entry = 0;

void add_tlb_entry(uint8_t page, uint8_t frame){
	if(last_entry == 16){
		int i = 0;
		int min_index = 0;
		for(i = 0; i < last_entry; i++){
			if(tlb[min_index].access > tlb[i].access){
				min_index = i;
			}
		}
		last_entry--;
		tlb[min_index].page_index = tlb[last_entry].page_index;
		tlb[min_index].frame_index = tlb[last_entry].frame_index;
		tlb[min_index].access = tlb[last_entry].access;
	}
	tlb[last_entry].page_index = page;
	tlb[last_entry].frame_index = frame;
	tlb[last_entry].access = 0;
	last_entry++;

}

uint8_t l_to_p(const logical_addr* logical, int* tlb_hit){
	short find = 0;
	int i;
	for(i = 0; i < last_entry; i++){
		if(tlb[i].page_index == logical->page_number){
			tlb[i].access++;
			find = 1;
			if(tlb_hit) *tlb_hit = 1;
			return tlb[i].frame_index;
		}
	}
	if(!find){
		if(tlb_hit) *tlb_hit = 0;
		uint8_t frame = get_base_addr(logical->page_number);
		add_tlb_entry(logical->page_number, frame);
		return frame;
	}
}

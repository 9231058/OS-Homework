#include "memory.h"
#include <stdio.h>
#include <stdint.h>

void mem_write(uint8_t frame, uint8_t offset, uint8_t input){
}

uint8_t mem_read(uint8_t frame, uint8_t offset){
	FILE* memory = fopen("memory", "r");
	uint8_t ret;
	fread(&ret, sizeof(uint8_t), 1, memory);
	return ret;
}

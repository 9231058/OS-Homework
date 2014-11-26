#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>

uint8_t mem_read(uint8_t frame, uint8_t offset);
void mem_write(uint8_t frame, uint8_t offset, uint8_t input);

#endif

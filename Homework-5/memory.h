// In The Name Of God
// ========================================
// * File Name : memory.h
// 
// * Creation Date : 28-11-2014
//
// * Last Modified : Fri 28 Nov 2014 08:28:31 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>

uint8_t mem_read(uint8_t frame, uint8_t offset);
void mem_write(uint8_t frame, uint8_t offset, uint8_t input);

#endif

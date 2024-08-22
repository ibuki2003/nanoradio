#pragma once
#include <stdint.h>
#include <sys/types.h>

uint8_t my_itoa(uint16_t v, uint8_t* ptr, uint8_t limit);
void my_strcpy(uint8_t* dst, const uint8_t* src);


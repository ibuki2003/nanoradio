#include "utils.h"

uint8_t my_itoa(uint16_t v, uint8_t* ptr, uint8_t limit) {
  uint8_t i = 0;
  do {
    *ptr = '0' + (v % 10);
    --ptr;
    ++i;
    if (i >= limit) break;
    v /= 10;
  } while (v);
  return i;
}

void my_strcpy(uint8_t* dst, const uint8_t* src) {
  for (uint i = 0; i < 8; ++i) { dst[i] = ' '; }
  for (uint i = 0; i < 8 && *src; ++i) {
    dst[i] = *src++;
  }
}


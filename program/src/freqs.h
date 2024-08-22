#pragma once
#include <stdint.h>

typedef struct FreqMemory {
  uint16_t freq;
  const char* name;
} FreqMemory;

extern const FreqMemory* const FREQS_AM[8];
extern const FreqMemory* const FREQS_FM[8];

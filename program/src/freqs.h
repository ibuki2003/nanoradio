#pragma once
#include <stdint.h>

typedef struct FreqMemory {
  uint16_t freq;
  const char* name;
} FreqMemory;

const FreqMemory* const FREQS_AM[8];
const FreqMemory* const FREQS_FM[8];

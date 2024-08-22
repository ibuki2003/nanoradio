#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct FreqMemory {
  uint16_t freq;
  const char* name;
} FreqMemory;

extern const FreqMemory* const FREQS_AM[8];
extern const FreqMemory* const FREQS_FM[8];

void find_station_refresh(uint16_t freq, bool am, uint8_t area);
char const* find_station(uint16_t freq, bool am, uint8_t area);

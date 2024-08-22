#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct FreqMemory {
  uint16_t freq;
  const char* name;
} FreqMemory;

#define AREA_COUNT 8

extern const FreqMemory* const FREQS_AM[AREA_COUNT];
extern const FreqMemory* const FREQS_FM[AREA_COUNT];
extern const char* const AREAS[AREA_COUNT];

void find_station_refresh(uint16_t freq, bool am, uint8_t area);
char const* find_station(uint16_t freq, bool am, uint8_t area);

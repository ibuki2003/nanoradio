#pragma once
#include <stdint.h>

extern uint8_t button_hold[3];
extern uint8_t button_release[3];
extern uint8_t handled_buttons;
uint8_t get_buttons();

// set buttons to ignore until released
inline void mark_buttons_handled(uint8_t buttons) {
  handled_buttons |= buttons;
}

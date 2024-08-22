#include "buttons.h"
#include <adc.h>
#include <ch32v003fun.h>
#include <stdbool.h>

uint8_t button_hold[3] = {};
uint8_t button_release[3] = {};

void mark_buttons_handled(uint8_t buttons);
uint8_t handled_buttons = 0;

uint8_t get_buttons() {

  static uint8_t adc_state = 255;

  // get raw state
  bool button_state[3];
  button_state[0] = button_state[2] = 0;
  button_state[1] = !funDigitalRead(PA1);
  uint8_t val = adc_get();
  if (val < 60) {
    button_state[2] = 1;
    adc_state = val;
  } else if (val < 180) {
    if (adc_state >= val) {
      // trigger only on decrease
      button_state[0] = 1;
      adc_state = 255;
    }
  }

  if (adc_state != 255) {
    // released completely
    if (val > 200) adc_state = 255;
    else adc_state = val;
  }

  uint8_t ret = 0;
  for (uint8_t i = 0; i < 3; ++i) {
    button_release[i] = 0;
    if (button_state[i]) {
      if (handled_buttons & (1 << i)) {
        button_hold[i] = 0;
      } else {
        if (button_hold[i] < 255) ++button_hold[i];
        ret |= (1 << i);
      }
    } else {
      if (!(handled_buttons & (1 << i))) {
        if (button_hold[i]) ret |= (1 << (i + 3));
        button_release[i] = button_hold[i];
      }
      button_hold[i] = 0;
      handled_buttons &= ~(1 << i);
    }
  }

  return ret;
}

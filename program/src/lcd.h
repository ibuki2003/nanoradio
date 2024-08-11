#pragma once

#include "ch32v003fun.h"
#include <stdint.h>
#include <i2c.h>

const int I2C_LCD_ADDR = 0x3e;

inline void LCD_send_command(uint8_t cmd) {
  uint8_t buf[2] = {0x00, cmd};
  i2c_send(I2C_LCD_ADDR, buf, 2);
  Delay_Us(30);
}

inline void LCD_init() {
  const uint8_t* cmds = (const uint8_t*)(
    "\x38\x39\x14"
      "\x73" // contrast set
      "\x56\x6C\x38\x0C"
      "\x01" // Clear Disp
  );
  while (*cmds) {
    AQM0802_send_command(*cmds);
    cmds++;
  }
}

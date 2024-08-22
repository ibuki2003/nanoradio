#include "lcd.h"

#include "ch32v003fun.h"
#include <i2c.h>

const uint8_t LCD_CUSTOM_FONT[] = {

  [CHAR_BLACK * 8] =
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,

  [CHAR_KANA_JI * 8]=
  0b00001,
  0b11010,
  0b00000,
  0b11001,
  0b00001,
  0b00010,
  0b11100,
  0b00000,

  // kanji chars are from k6x8 font
  [CHAR_KANJI_HOU * 8]=
  0b01010,
  0b11111,
  0b01011,
  0b01111,
  0b01111,
  0b10110,
  0b10101,
  0b00000,

  [CHAR_KANJI_SOU * 8]=
  0b10101,
  0b01111,
  0b00010,
  0b10111,
  0b10010,
  0b10101,
  0b11111,
  0b00000,

  [CHAR_KANJI_DAI * 8]=
  0b10010,
  0b11011,
  0b01001,
  0b11111,
  0b10100,
  0b01111,
  0b10101,
  0b00000,

};


void LCD_send_command(uint8_t cmd) {
  uint8_t buf[2] = {0x00, cmd};
  i2c_send(I2C_LCD_ADDR, buf, 2);
  Delay_Us(30);
}

void LCD_init() {
  const uint8_t* cmds = (const uint8_t*)(
    "\x38\x39\x14"
      "\x73" // contrast set
      "\x56\x6C\x38\x0C"
      "\x01" // Clear Disp
  );
  while (*cmds) {
    // note: these commands should be sent with delay
    LCD_send_command(*cmds);
    cmds++;
  }

  // NOTE: somewhy CGRAM command should be called twice
  LCD_send_command(0x40 | 0x00);
  LCD_send_command(0x40 | 0x00);

  I2C_ACQUIRE();
  i2c_raw_start(I2C_LCD_ADDR, false);
  i2c_raw_send(&(uint8_t){0x40}, 1, false);
  i2c_raw_send(LCD_CUSTOM_FONT, sizeof(LCD_CUSTOM_FONT), true);

}

void LCD_make_bar_font(uint8_t len) {
  uint8_t b = ~((1 << (5 - len)) - 1);

  LCD_send_command(0x40 | (CHAR_BAR_PART * 8));
  LCD_send_command(0x40 | (CHAR_BAR_PART * 8));
  i2c_send(I2C_LCD_ADDR, (uint8_t[]){
    0x40,
    b, b, b, b, b, b, b, b,
  }, 9);
}

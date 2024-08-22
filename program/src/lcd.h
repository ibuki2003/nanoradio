#pragma once

#include <stdint.h>

#define I2C_LCD_ADDR 0x3e

// user-defined characters
enum LCD_CUSTOM_CHAR {
  CHAR_BLACK,
  // specify value explicitly to ensure defined chars have right values
  CHAR_KANA_JI   = 1,
  CHAR_KANJI_HOU = 2,
  CHAR_KANJI_SOU = 3,
  CHAR_KANJI_DAI = 4,
  CHAR_BAR_PART,
};

#define ジ "\x01"
#define 放 "\x02"
#define 送 "\x03"
#define 第 "\x04"

typedef enum LCD_CUSTOM_CHAR LCD_CUSTOM_CHAR;

void LCD_send_command(uint8_t cmd);
void LCD_init();
void LCD_make_bar_font(uint8_t len);

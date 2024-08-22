#include "ch32v003fun.h"
#include <sys/types.h>
#include <stdint.h>

#include <buttons.h>
#include <adc.h>
#include <pwr.h>
#include <i2c.h>
#include <lcd.h>
#include <kt0913.h>
#include <freqs.h>
#include <utils.h>
#include <lcd_kana.h>

// will be called on startup and after wake-up
void setup() {
  SystemInit();
  RCC->APB1PCENR |= RCC_APB1Periph_I2C1;
  RCC->APB2PCENR |= (0
    | RCC_APB2Periph_AFIO
    | RCC_APB2Periph_GPIOA
    | RCC_APB2Periph_GPIOC
    // | RCC_APB2Periph_GPIOD
    | RCC_APB2Periph_ADC1
    | RCC_AFIOEN
  );

  funPinMode(PA1, GPIO_Speed_In | GPIO_CNF_IN_PUPD);   // btn2: pull-up
  funPinMode(PA2, GPIO_Speed_In | GPIO_CNF_IN_ANALOG); // btn1, 3: analog
  funPinMode(PC4, GPIO_Speed_2MHz | GPIO_CNF_OUT_PP);  // power FET

  // PC1: SDA, PC2: SCL
  funPinMode(PC1, GPIO_Speed_10MHz | GPIO_CNF_OUT_OD_AF);
  funPinMode(PC2, GPIO_Speed_10MHz | GPIO_CNF_OUT_OD_AF);

  funDigitalWrite(PC4, 0); // set down to turn on FET
  funDigitalWrite(PA1, 1); // pull-up

  // ADC Setup
  adc_init();

  i2c_setup();
}

typedef enum {
  MODE_NORMAL = 0,
  MODE_FREQ,
  MODE_CONFIG,
  MODE_SLEEP,
} Mode;

// global state
bool am = false;
uint16_t am_freq = 594;
uint16_t fm_freq = 847;
uint8_t vol = 16;
uint8_t area = 2; // kanto

void draw_l1(bool seeking) {
  uint8_t sbuf[9];
  sbuf[0] = 0x40;

  sbuf[2] = 'M';
  sbuf[3] = ' ';
  sbuf[4] = ' ';

  if (am) {
    // 12345678
    // AM  594k
    sbuf[1] = 'A';

    my_itoa(am_freq, &sbuf[7], 4);

    sbuf[8] = 'k';
  } else {
    // 12345678
    // FM 84.7M
    sbuf[1] = 'F';

    my_itoa(fm_freq, &sbuf[6], 4);

    sbuf[7] = sbuf[6];
    sbuf[6] = '.';
    sbuf[8] = 'M';
  }

  if (seeking) {
    if (sbuf[3] == ' ') sbuf[3] = 0xfb;
    sbuf[8] = 0xfc;
  }

  LCD_send_command(0x80);
  i2c_send(I2C_LCD_ADDR, sbuf, 9);
}

void draw_station_name() {
  uint8_t sbuf[9];
  sbuf[0] = 0x40;

  char const* const name = find_station(am ? am_freq : fm_freq, am, area);
  if (name) {
    my_strcpy(&sbuf[1], (const uint8_t*)name);
  } else {
    sbuf[1] = '-';
    for (uint i = 2; i < 9; ++i) sbuf[i] = ' ';
  }

  // on line 2
  LCD_send_command(0x80 | 0x40);
  i2c_send(I2C_LCD_ADDR, sbuf, 9);
}

void add_freq(int8_t d) {
  if (am) {
    am_freq += 9 * d;
    if (am_freq < AM_FREQ_MIN) am_freq = AM_FREQ_MAX;
    if (am_freq > AM_FREQ_MAX) am_freq = AM_FREQ_MIN;
    KT0913_set_freq_am(am_freq);
  } else {
    fm_freq += 1 * d;
    if (fm_freq < FM_FREQ_MIN) fm_freq = FM_FREQ_MAX;
    if (fm_freq > FM_FREQ_MAX) fm_freq = FM_FREQ_MIN;
    KT0913_set_freq_fm(fm_freq);
  }
}

#define LOOP_INTERVAL 10

#define VOLUME_SHOW_TIMEOUT 50
Mode run_normal() {
  // initialize
  draw_l1(false);
  draw_station_name();

  uint16_t volume_timeout = 0;

  while(1) {

    uint8_t k = get_buttons();
    bool timedout = volume_timeout == 1;
    if (volume_timeout) volume_timeout--;

    if (k || timedout) {

      if (button_hold[0] % 8 == 1) {
        if (vol > 0) --vol;
        KT0913_set_vol(vol);
        volume_timeout = VOLUME_SHOW_TIMEOUT;
      }
      if (button_hold[2] % 8 == 1) {
        if (vol < 31) ++vol;
        KT0913_set_vol(vol);
        volume_timeout = VOLUME_SHOW_TIMEOUT;
      }

      if (button_release[1]) {
        return MODE_FREQ;
      }

      if (button_hold[1] >= 200) {
        mark_buttons_handled(0b010);
        // go to sleep
        // turn off FET
        funDigitalWrite(PC4, 1);
        // wait for release
        while (funDigitalRead(PA1) == 0) {}
        return MODE_SLEEP;
      }

      // draw

      // freq won't change
      // draw_l1(false);

      if (volume_timeout) {
        uint8_t sbuf[9];
        sbuf[0] = 0x40;
        for (uint i = 1; i < 9; ++i) sbuf[i] = ' ';

        uint16_t v = vol;
        if (v == 1) v = 0;
        uint8_t bar_len = v / 5;
        if (bar_len)
          for (uint i = 0; i < bar_len; ++i)
            sbuf[i+1] = CHAR_BLACK;
        sbuf[bar_len+1] = CHAR_BAR_PART;

        LCD_make_bar_font(v % 5);

        v = vol == 31 ? 99 : vol * 100 / 31;
        my_itoa(v, &sbuf[8], 2);

        LCD_send_command(0x80 | 0x40);
        i2c_send(I2C_LCD_ADDR, sbuf, 9);
      } else {
        draw_station_name();
      }
    }

    Delay_Ms(LOOP_INTERVAL);
  }
}

#define FREQ_TIMEOUT 200
Mode run_freq() {
  uint16_t timeout = FREQ_TIMEOUT;
  // initialize
  draw_l1(true);
  draw_station_name();

  while(1) {

    uint8_t k = get_buttons();

    if (k) {
      timeout = FREQ_TIMEOUT;
      if (button_hold[0] == 1 || button_hold[0] >= 50) {
        add_freq(-1);
      }
      if (button_hold[2] == 1 || button_hold[2] >= 50) {
        add_freq(1);
      }

      if (button_release[1]) {
        am = !am;
        KT0913_set_amfm(am);
      }

      if (button_hold[1] >= 200) {
        mark_buttons_handled(0b010);
        // go to config
        return MODE_CONFIG;
      }

      // draw
      draw_l1(true);
      draw_station_name();
    }

    if (--timeout == 0) {
      return MODE_NORMAL;
    }

    Delay_Ms(LOOP_INTERVAL);
  }
}

#define CONFIG_TIMEOUT 1000
Mode run_config() {
  uint16_t timeout = CONFIG_TIMEOUT;
  // initialize

  uint8_t sbuf[9];
  sbuf[0] = 0x40;

  LCD_send_command(0x80);
  i2c_send(I2C_LCD_ADDR, (const uint8_t*)("\x40" ｴ ﾘ ｱ ｾ ｯ ﾃ ｲ " "), 9);


  my_strcpy(&sbuf[1], (const uint8_t*)AREAS[area]);
  LCD_send_command(0x80 | 0x40);
  i2c_send(I2C_LCD_ADDR, sbuf, 9);

  while(1) {

    uint8_t k = get_buttons();

    if (k) {
      timeout = FREQ_TIMEOUT;
      if (button_hold[0] % 16 == 1) {
        area = (area + AREA_COUNT - 1) % AREA_COUNT;
      }
      if (button_hold[2] == 1 || button_hold[2] >= 50) {
        area = (area + 1) % AREA_COUNT;
      }

      if (button_release[1] || button_hold[1] >= 200) {
        mark_buttons_handled(0b010);
        return MODE_NORMAL;
      }

      // draw
      my_strcpy(&sbuf[1], (const uint8_t*)AREAS[area]);
      LCD_send_command(0x80 | 0x40);
      i2c_send(I2C_LCD_ADDR, sbuf, 9);
    }

    if (--timeout == 0) {
      return MODE_NORMAL;
    }

    Delay_Ms(LOOP_INTERVAL);
  }
}

void inner_main() {
  // here cpu is after power-up or wake-up
  setup();

  Delay_Ms(300);

  // reset button state
  get_buttons();
  mark_buttons_handled(0b111);

  // Initialize IC
  KT0913_init();
  KT0913_set_vol(vol);

  // Initialize LCD
  LCD_init();

  KT0913_set_amfm(am);
  KT0913_set_freq_fm(fm_freq);

  find_station_refresh(am ? am_freq : fm_freq, am, area);

  Mode mode = MODE_NORMAL;
  while (true) {
    switch (mode) {
      case MODE_NORMAL:
        mode = run_normal();
        break;
      case MODE_FREQ:
        mode = run_freq();
        break;
      case MODE_CONFIG:
        mode = run_config();
        break;
      case MODE_SLEEP:
        Delay_Ms(100);
        sleep();
        return; // Run setup again
        break;
    }
    Delay_Ms(LOOP_INTERVAL);
  }

}


int main() {
  while (1) {
    inner_main();
  }
}

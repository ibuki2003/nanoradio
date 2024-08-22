#include "ch32v003fun.h"
#include <sys/types.h>
#include <stdint.h>

#include <buttons.h>
#include <adc.h>
#include <pwr.h>
#include <i2c.h>
#include <lcd.h>
#include <kt0913.h>

#include "freqs.h"
#include "utils.h"

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

// global state
bool am = true;
uint16_t am_freq = 594;
uint16_t fm_freq = 847;
uint8_t vol = 16;
uint8_t area = 2; // kanto

void draw_l1() {
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

  LCD_send_command(0x80);
  i2c_send(I2C_LCD_ADDR, sbuf, 9);
}

void draw_station_name() {
  uint8_t sbuf[9];
  for (uint i = 1; i < 9; ++i) sbuf[i] = ' ';
  sbuf[0] = 0x40;
  {
    FreqMemory const* ptr = am ? FREQS_AM[area] : FREQS_FM[area];
    uint16_t targ_freq = am ? am_freq : fm_freq;
    for (; ptr->freq <= targ_freq; ++ptr) {
      if (ptr->freq == targ_freq) {
        my_strcpy(sbuf + 1, (const uint8_t*)ptr->name);
        break;
      }
    }
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

void inner_main() {
  // here cpu is after power-up or wake-up
  setup();

  Delay_Ms(300);
  get_buttons(); // reset button state

  // Initialize IC
  KT0913_init();
  KT0913_set_vol(vol);

  // Initialize LCD
  LCD_init();

  uint8_t buf[2];
  uint8_t cnt = 0;
  uint8_t sbuf[9];

  KT0913_set_amfm(am);
  KT0913_set_freq_fm(fm_freq);

  draw_l1();

  uint8_t v;
  while(1) {

    uint8_t k = get_buttons();

    if (k) {
      if (button_hold[0] == 1 || button_hold[0] >= 50) {
        add_freq(-1);
        draw_l1();
        draw_station_name();
      }
      if (button_release[1]) {
        am = !am;
        KT0913_set_amfm(am);
        add_freq(0);
        draw_l1();
        draw_station_name();
      }
      if (button_hold[1] >= 100) {
        // go to sleep
        // turn off FET
        funDigitalWrite(PC4, 1);
        // wait for release
        while (funDigitalRead(PA1) == 0) {}
        Delay_Ms(100);
        sleep();
        return; // setup again
      }
      if (button_hold[2] == 1 || button_hold[2] >= 50) {
        add_freq(1);
        draw_l1();
        draw_station_name();
      }
    }

    Delay_Ms(LOOP_INTERVAL);
  }

}


int main() {
  while (1) {
    inner_main();
  }
}

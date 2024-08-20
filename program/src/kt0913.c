#include "kt0913.h"

const uint8_t init_data[] = {
  // NOTE: each address has 16bit data
  0x04, 0b00100000, 0b10000000, // VOLUME
  0x05, 0b00010000, 0b00000000, // DSPCFGA
  0x0c, 0x00, 0b00101100, // LOCFGC
  0x0f, 0b10001000, 0b00011111, // RXCFG
  0x22, 0b10101111, 0b11000100, // AMDSP

  0x16, 0b10000000, 0b00000010, // AMSYSCFG

  0x2e, 0b00100000, 0b00010000, // SOFTMUTE
  0,
};

void KT0913_init() {
  uint8_t const* p = init_data;
  while (*p) {
    while (i2c_send(I2C_KT0913_ADDR, p, 3));
    p += 3;
  }
}

uint8_t KT0913_set_amfm(bool am);
uint8_t KT0913_set_freq_am(uint16_t freq);
uint8_t KT0913_set_freq_fm(uint16_t freq);
uint8_t KT0913_set_vol(uint8_t vol);
uint8_t KT0913_get_amrssi();
uint8_t KT0913_get_fmrssi();
uint8_t KT0913_get_fmsnr();

#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <i2c.h>

#define I2C_KT0913_ADDR 0x35
#define FM_FREQ_MIN 320
#define FM_FREQ_MAX 1100
#define AM_FREQ_MIN 500
#define AM_FREQ_MAX 1710

void KT0913_init();

inline uint8_t KT0913_set_amfm(bool am) {
  return i2c_send(I2C_KT0913_ADDR, (uint8_t[]) {
    // AMSYSCFG
    0x16,
    am << 7,
    0b00000010,
  }, 3) ?: i2c_send(I2C_KT0913_ADDR, (uint8_t[]) {
    // SOFTMUTE
    0x2e,
    0b00100000,
    0b10000001 | ((!am) << 3)
  }, 3);
}

inline uint8_t KT0913_set_freq_am(uint16_t freq) {
  return i2c_send(I2C_KT0913_ADDR, (uint8_t[]) {
    // AMCHAN
    0x17,
    0x80 | freq >> 8,
    freq & 0xFF,
  }, 3);
}

inline uint8_t KT0913_set_freq_fm(uint16_t freq) {
  freq *= 2; // given in 0.1MHz, need to convert to 0.05MHz

  return i2c_send(I2C_KT0913_ADDR, (uint8_t[]) {
    // FMTUNE
    0x03,
    0x80 | freq >> 8,
    freq & 0xFF,
  }, 3);
}

inline uint8_t KT0913_set_vol(uint8_t vol) {
  return i2c_send(I2C_KT0913_ADDR, (uint8_t[]) {
    // VOL
    0x0f,
    0b10001000,
    vol,
  }, 3);
}

inline uint8_t KT0913_get_amrssi() {
  uint8_t buf[2];
  i2c_send_recv(I2C_KT0913_ADDR, (uint8_t[]) { 0x24 }, 1, buf, 2);
  return buf[0];
}

inline uint8_t KT0913_get_fmrssi() {
  uint8_t buf[2];
  i2c_send_recv(I2C_KT0913_ADDR, (uint8_t[]) { 0x12 }, 1, buf, 2);
  return buf[1] >> 3;
}

inline uint8_t KT0913_get_fmsnr() {
  uint8_t buf[2];
  i2c_send_recv(I2C_KT0913_ADDR, (uint8_t[]) { 0x14 }, 1, buf, 2);
  return (buf[0] & 0x1f) << 2 | buf[1] >> 6;
}


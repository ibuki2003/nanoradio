#pragma once
#include <ch32v003fun.h>
#include <stdbool.h>
#include <stdint.h>

#define I2C_CLKRATE 50000
#define I2C_PRERATE 200000

uint8_t i2c_raw_start(uint8_t addr, bool recv);
uint8_t i2c_raw_send(const uint8_t *data, uint8_t sz, bool last);
uint8_t i2c_raw_recv(uint8_t *data, uint8_t sz, bool last);

inline uint8_t i2c_send(uint8_t addr, const uint8_t* data, uint8_t sz) {
  return i2c_raw_start(addr, false) ?: i2c_raw_send(data, sz, true);
}
inline uint8_t i2c_recv(uint8_t addr, uint8_t* data, uint8_t sz) {
  return i2c_raw_start(addr, true) ?: i2c_raw_recv(data, sz, true);
}

inline uint8_t i2c_send_recv(uint8_t addr, const uint8_t* send, uint8_t send_size, uint8_t* recv, uint8_t recv_size) {
  return (
    i2c_raw_start(addr, false) ?:
    i2c_raw_send(send, send_size, false) ?:
    i2c_raw_start(addr, true) ?:
    i2c_raw_recv(recv, recv_size, true)
  );
}

inline void i2c_setup() {
  // reset I2C1
  RCC->APB1PRSTR |= RCC_APB1Periph_I2C1;
  RCC->APB1PRSTR &= ~RCC_APB1Periph_I2C1;

  I2C1->CTLR2 = (
    I2C1->CTLR2 & ~I2C_CTLR2_FREQ
      | (FUNCONF_SYSTEM_CORE_CLOCK / I2C_PRERATE) & I2C_CTLR2_FREQ);

  I2C1->CKCFGR = (FUNCONF_SYSTEM_CORE_CLOCK / (2*I2C_CLKRATE)) & I2C_CKCFGR_CCR;

  I2C1->CTLR1 |= I2C_CTLR1_PE | I2C_CTLR1_ACK;
}

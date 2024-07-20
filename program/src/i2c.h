#pragma once
#include <stdint.h>

uint8_t i2c_send(uint8_t addr, const uint8_t *data, uint8_t sz);
uint8_t i2c_recv(uint8_t addr, uint8_t *data, uint8_t sz);

inline uint8_t i2c_send_recv(uint8_t addr, const uint8_t* send, uint8_t send_size, uint8_t* recv, uint8_t recv_size) {
  return i2c_send(addr, send, send_size)
    ?: i2c_recv(addr, recv, recv_size);
}

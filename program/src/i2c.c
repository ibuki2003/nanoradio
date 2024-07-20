#include "i2c.h"
#include <ch32v003fun.h>

uint8_t i2c_send_recv(uint8_t addr, const uint8_t* send, uint8_t send_size, uint8_t* recv, uint8_t recv_size);

#define TIMEOUT_MAX 100000
#define WAIT_WHILE_TIMEOUT(expr) { int32_t timeout = TIMEOUT_MAX; while((expr) && --timeout); if(timeout==0) return 1; }

inline static uint8_t i2c_chk_evt(uint32_t event_mask) {
	/* read order matters here! STAR1 before STAR2!! */
	uint32_t status = I2C1->STAR1 | (I2C1->STAR2<<16);
	return (status & event_mask) == event_mask;
}

/*
 * low-level packet send for blocking polled operation via i2c
 */
uint8_t i2c_send(uint8_t addr, const uint8_t *data, uint8_t sz)
{

  WAIT_WHILE_TIMEOUT(I2C1->STAR2 & I2C_STAR2_BUSY);

	// Set START condition
	I2C1->CTLR1 |= I2C_CTLR1_START;

	// wait for master mode select
	WAIT_WHILE_TIMEOUT(!i2c_chk_evt(I2C_EVENT_MASTER_MODE_SELECT));

	// send 7-bit address + write flag
	I2C1->DATAR = addr<<1;

	// wait for transmit condition
	WAIT_WHILE_TIMEOUT(!i2c_chk_evt(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

	// send data one byte at a time
	while(sz--) {
		// wait for TX Empty
    WAIT_WHILE_TIMEOUT(!(I2C1->STAR1 & I2C_STAR1_TXE));

		// send command
		I2C1->DATAR = *data++;
	}

	// wait for tx complete
	WAIT_WHILE_TIMEOUT(!i2c_chk_evt(I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	// set STOP condition
	I2C1->CTLR1 |= I2C_CTLR1_STOP;

	// we're happy
	return 0;
}

uint8_t i2c_recv(uint8_t addr, uint8_t *data, uint8_t sz)
{

  WAIT_WHILE_TIMEOUT(I2C1->STAR2 & I2C_STAR2_BUSY);

	// Set START condition
	I2C1->CTLR1 |= I2C_CTLR1_START;

	// wait for master mode select
	WAIT_WHILE_TIMEOUT(!i2c_chk_evt(I2C_EVENT_MASTER_MODE_SELECT));

	// send 7-bit address + read flag
	I2C1->DATAR = addr<<1 | 1;

	// wait for transmit condition
	WAIT_WHILE_TIMEOUT(!i2c_chk_evt(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

	// send data one byte at a time
	while(sz--) {
		// wait for TX Empty
    /* WAIT_WHILE_TIMEOUT(!(I2C1->STAR1 & I2C_STAR1_TXE)); */
    WAIT_WHILE_TIMEOUT(!i2c_chk_evt(I2C_EVENT_MASTER_BYTE_RECEIVED));

		// send command
		*data++ = I2C1->DATAR;
	}

	// set STOP condition
	I2C1->CTLR1 |= I2C_CTLR1_STOP;

	// we're happy
	return 0;
}


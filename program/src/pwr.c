#include "pwr.h"
#include <ch32v003fun.h>

void sleep() {
  // use PUPD input to reduce power consumption
  GPIOA->CFGLR = 0x88888888;
  GPIOC->CFGLR = 0x88888888;
  GPIOC->BSHR = 0xff << 16; // clear all
  GPIOC->BSHR = 0xff << 16; // clear all

  funDigitalWrite(PA1, 1); // pull-up (wakeup button)
  funDigitalWrite(PA2, 1); // keep up (ADC buttons)

  // turn off FET
  funPinMode(PC4, GPIO_Speed_2MHz | GPIO_CNF_OUT_PP);
  funDigitalWrite(PC4, 1);

  RCC->APB2PCENR = 0;
  RCC->APB1PCENR = 0;

  AFIO->EXTICR = AFIO_EXTICR_EXTI1_PA; // PA1 as EXTI1
  EXTI->EVENR |= EXTI_Line1;
  EXTI->FTENR |= EXTI_Line1; // falling edge

  RCC->RSTSCKR &= ~RCC_LSION;
  RCC->APB1PCENR |=  RCC_PWREN;

  PWR->CTLR |= PWR_CTLR_PDDS; // Power Down Deep Sleep
  PFIC->SCTLR |= 1<<2; // set deepsleep

  __WFE();
}

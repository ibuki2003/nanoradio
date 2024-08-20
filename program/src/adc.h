#pragma once
#include <ch32v003fun.h>

inline void adc_init() {
  RCC->CFGR0 &= ~(RCC_ADCPRE | RCC_PPRE2); // adcpre div2


  // Reset ADC
  RCC->APB1PRSTR |= RCC_APB2Periph_ADC1;
  RCC->APB1PRSTR &= ~RCC_APB2Periph_ADC1;

  // ch0 to A0
  ADC1->RSQR1 = 0;
  ADC1->RSQR2 = 0;
  ADC1->RSQR3 = 0;

  ADC1->SAMPTR2 &= ~ADC_SMP0;
  ADC1->SAMPTR2 |= 0 << 0; // sample time 3 cycles

  ADC1->CTLR2 |= ADC_ADON | ADC_EXTSEL;

  // Reset calibration
  ADC1->CTLR2 |= ADC_RSTCAL;
  while (ADC1->CTLR2 & ADC_RSTCAL);

  // Calibrate
  ADC1->CTLR2 |= ADC_CAL;
  while (ADC1->CTLR2 & ADC_CAL);
}

inline uint8_t adc_get() {
  ADC1->CTLR2 |= ADC_SWSTART;
  while (!(ADC1->STATR & ADC_EOC));
  return ADC1->RDATAR >> 2;
}

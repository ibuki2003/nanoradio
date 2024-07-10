#include "ch32v003fun.h"
#include <stdio.h>

int main() {
  SystemInit();

  // Enable GPIOs
  funGpioInitAll();
  
  funPinMode( PC4, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );

  while(1)
  {
    funDigitalWrite( PC4, FUN_HIGH );
    puts("On");
    Delay_Ms( 250 );
    funDigitalWrite( PC4, FUN_LOW );
    puts("Off");
    Delay_Ms( 250 );
  }
}

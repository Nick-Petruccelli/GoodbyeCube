#include "stm32f4xx.h"
#include <stdint.h>

#define LED_PIN 5

int main() {
  RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN_Pos);

  volatile uint32_t dummy;
  dummy = RCC->AHB1ENR;
  dummy = RCC->AHB1ENR;

  GPIOA->MODER |= (1 << GPIO_MODER_MODER5_Pos);

  while (1) {
    GPIOA->ODR ^= (1 << LED_PIN);
    for (int i = 0; i < 1000000; i++) {
      __asm__("nop");
    }
  }
}

#include "stm32f446xx.h"
#include "system_stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>

#define LED_PIN 5
#define ADC1_DR_ADDR ((uint32_t)&ADC1->DR)

volatile uint32_t ticks = 0;
volatile uint16_t adc_buff[2] = {0};

void clock_init() {
  // Enable HSE Bypass and turn on HSE in RCC
  RCC->CR |= RCC_CR_HSEBYP_Msk | RCC_CR_HSEON_Msk;
  while (!(RCC->CR & RCC_CR_HSERDY_Msk))
    ;

  // Set AHP1 to power enable
  RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
  volatile uint32_t dummy;
  dummy = RCC->APB1ENR;
  dummy = RCC->APB1ENR;

  // Set syttem clock to HSE
  RCC->CFGR |= (RCC_CFGR_SW_HSE << RCC_CFGR_SW_Pos);
  while (!(RCC->CFGR & RCC_CFGR_SWS_HSE))
    ;

  // Set over-drive to reach max Mhz
  PWR->CR |= PWR_CR_ODEN_Msk;
  while (!(PWR->CSR & PWR_CSR_ODRDY_Msk))
    ;

  PWR->CR |= PWR_CR_ODSWEN_Msk;
  while (!(PWR->CSR & PWR_CSR_ODSWRDY_Msk))
    ;

  // Set volatage scaleing to 1 to mach max clock frequency requierments (vos =
  // 1 -> 180Mhz)
  PWR->CR |= (0b11 << PWR_CR_VOS_Pos);

  // Set flash read latency to match clk cycles and volatage
  FLASH->ACR |= (5 << FLASH_ACR_LATENCY_Pos);

  RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN_Pos);

  // Configure the PLL
  RCC->PLLCFGR &=
      ~(RCC_PLLCFGR_PLLM_Msk | RCC_PLLCFGR_PLLP_Msk | RCC_PLLCFGR_PLLN_Msk);
  RCC->PLLCFGR |= (4 << RCC_PLLCFGR_PLLM_Pos) | (180 << RCC_PLLCFGR_PLLN_Pos) |
                  (0 << RCC_PLLCFGR_PLLP_Pos);
  RCC->PLLCFGR |= (1 << RCC_PLLCFGR_PLLSRC_Pos);

  // Turn on PLL
  RCC->CR |= (1 << RCC_CR_PLLON_Pos);
  while (!(RCC->CR & RCC_CR_PLLRDY_Msk))
    ;

  // Set PLLP as system clock
  RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);
  while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
    ;
}

void adc_init() {
  // Enable clock for ADC1
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

  // Set GPIO pins to analog
  GPIOA->MODER |=
      (0b11 << GPIO_MODER_MODE0_Pos) | (0b11 << GPIO_MODER_MODE1_Pos);

  // Disable adc1 as we config
  ADC1->CR2 &= ~ADC_CR2_ADON;

  // Set pre-scaler
  ADC->CCR &= ~ADC_CCR_ADCPRE;
  ADC->CCR |= (0b00 << ADC_CCR_ADCPRE_Pos);

  // Set scan mode
  ADC1->CR1 |= ADC_CR1_SCAN;

  // Enable continuos conversion
  ADC1->CR2 |= ADC_CR2_CONT;

  // Enable DMA mode
  ADC1->CR2 |= ADC_CR2_DMA | ADC_CR2_DDS;

  // Set sequence length to 2
  ADC1->SQR1 &= ~ADC_SQR1_L;
  ADC1->SQR1 |= (1 << ADC_SQR1_L_Pos);

  // Configure sequence slots
  // TODO: Might be wrong I might have to use ADC_SQR3_SQ1_0 ADC_SQR3_SQ1_1
  ADC1->SQR3 = (0 << 0) | (1 << 5);

  // Sampling time
  ADC1->SMPR2 |= (3 << (3 * 0)) | (3 << (3 * 1));

  // Enable ADC
  ADC1->CR2 |= ADC_CR2_ADON;

  // Start continuous conversion via software
  ADC1->CR2 |= ADC_CR2_SWSTART;
}

void dma_init() {
  // Enable clock for DMA
  RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

  // Disable DMA before config
  DMA2_Stream0->CR &= ~DMA_SxCR_EN;
  while (DMA2_Stream0->CR & DMA_SxCR_EN)
    ;

  // Clear flags
  DMA2->LIFCR = 0x3D;

  // Set peripheral address
  DMA2_Stream0->PAR = ADC1_DR_ADDR;

  // Set memory address for out buf
  DMA2_Stream0->M0AR = (uint32_t)adc_buff;

  // Number of transfers
  DMA2_Stream0->NDTR = 2;

  // Select channel 0
  DMA2_Stream0->CR &= ~DMA_SxCR_CHSEL;

  // Set Peripheral-to-Memory
  DMA2_Stream0->CR &= ~DMA_SxCR_DIR;

  // Set Circluar mode
  DMA2_Stream0->CR |= DMA_SxCR_CIRC;

  // Increment memory pointer, not peripheral
  DMA2_Stream0->CR |= DMA_SxCR_MINC;

  // Data size: 16-bit
  DMA2_Stream0->CR |= (1 << DMA_SxCR_PSIZE_Pos) | (1 << DMA_SxCR_MSIZE_Pos);

  // Set Peripheral-to-Memory
  DMA2_Stream0->CR |= (1 << DMA_SxCR_PL_Pos);

  // Enable DMA stream
  DMA2_Stream0->CR |= DMA_SxCR_EN;
}

void systick_handler(void) { ticks++; }

void deley_ms(uint32_t ms) {
  uint32_t start = ticks;
  uint32_t end = start + ms;
  if (end < start) {
    while (start <= ticks)
      ;
  }
  while (ticks < end)
    ;
}

int main() {
  clock_init();
  adc_init();
  dma_init();
  SysTick_Config(180000);
  __enable_irq();

  volatile uint32_t dummy;
  dummy = RCC->AHB1ENR;
  dummy = RCC->AHB1ENR;

  GPIOA->MODER |= (1 << GPIO_MODER_MODER5_Pos);

  uint16_t x_max = 0;
  uint16_t x_min = 65535;
  uint16_t y_max = 0;
  uint16_t y_min = 65535;

  while (1) {
    if (adc_buff[0] > x_max)
      x_max = adc_buff[0];
    if (adc_buff[0] < x_min)
      x_min = adc_buff[0];
    if (adc_buff[1] > y_max)
      y_max = adc_buff[1];
    if (adc_buff[1] < y_min)
      y_min = adc_buff[1];
    // GPIOA->ODR ^= (1 << LED_PIN);
    // deley_ms(1000);
  }
}

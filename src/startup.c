#include <stdint.h>

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;

#define SRAM_START 0x20000000U
#define SRAM_SIZE (128U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADD (SRAM_END)

#define IST_VECTOR_SIZE_WORDS 112

void main(void);

void reset_handler(void);
void default_handelr(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_moniter_handler(void)
    __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));
void wwdg_handler(void) __attribute__((weak, alias("default_handler")));
void pvd_handler(void) __attribute__((weak, alias("default_handler")));
void tamp_stamp_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_wkup_handler(void) __attribute__((weak, alias("default_handler")));
void flash_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream0_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream1_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream2_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream3_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream5_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream6_handler(void) __attribute__((weak, alias("default_handler")));
void adc_handler(void) __attribute__((weak, alias("default_handler")));
void can1_tx_handler(void) __attribute__((weak, alias("default_handler")));
void can1_rx0_handler(void) __attribute__((weak, alias("default_handler")));
void can1_rx1_handler(void) __attribute__((weak, alias("default_handler")));
void can1_sce_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_5_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_tim9_handler(void)
    __attribute__((weak, alias("default_handler")));
void tim1_up_tim10_handler(void)
    __attribute__((weak, alias("default_handler")));
void tim1_trg_com_tim11_handler(void)
    __attribute__((weak, alias("default_handler")));
void tim1_cc_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_handler(void) __attribute__((weak, alias("default_handler")));
void usart3_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_10_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_alarm_handler(void) __attribute__((weak, alias("default_handler")));
void otg_fs_wkup_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_brk_tim12_handler(void)
    __attribute__((weak, alias("default_handler")));
void tim8_up_tim13_handler(void)
    __attribute__((weak, alias("default_handler")));
void tim8_trg_com_tim14_handler(void)
    __attribute__((weak, alias("default_handler")));
void tim8_cc_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream7_handler(void) __attribute__((weak, alias("default_handler")));
void fmc_handler(void) __attribute__((weak, alias("default_handler")));
void sdio_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_handler(void) __attribute__((weak, alias("default_handler")));
void uart4_handler(void) __attribute__((weak, alias("default_handler")));
void uart5_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_dac_handler(void) __attribute__((weak, alias("default_handler")));
void tim7_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream0_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream1_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream2_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream3_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream4_handler(void) __attribute__((weak, alias("default_handler")));
void can2_tx_handler(void) __attribute__((weak, alias("default_handler")));
void can2_rx0_handeler(void) __attribute__((weak, alias("default_handler")));
void can2_rx1_handler(void) __attribute__((weak, alias("default_handler")));
void can2_sce_handler(void) __attribute__((weak, alias("default_handler")));
void otg_fs_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream5_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream6_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream7_handler(void) __attribute__((weak, alias("default_handler")));
void usart6_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_er_handler(void) __attribute__((weak, alias("default_handler")));
void otg_hs_ep1_out_handler(void)
    __attribute__((weak, alias("default_handler")));
void otg_hs_ep1_in_handler(void)
    __attribute__((weak, alias("default_handler")));
void otg_hs_wkup_handler(void) __attribute__((weak, alias("default_handler")));
void otg_hs_handler(void) __attribute__((weak, alias("default_handler")));
void dcmi_handler(void) __attribute__((weak, alias("default_handler")));
void fpu_handler(void) __attribute__((weak, alias("default_handler")));
void spi4_handler(void) __attribute__((weak, alias("default_handler")));
void sai1_handler(void) __attribute__((weak, alias("default_handler")));
void sai2_handler(void) __attribute__((weak, alias("default_handler")));
void quadspi_handler(void) __attribute__((weak, alias("default_handler")));
void hdmi_cec_handler(void) __attribute__((weak, alias("default_handler")));
void spdif_rx_handler(void) __attribute__((weak, alias("default_handler")));
void fmpi2c1_handler(void) __attribute__((weak, alias("default_handler")));
void fmpi2c1_error_handler(void)
    __attribute__((weak, alias("default_handler")));

uint32_t isr_vector[IST_VECTOR_SIZE_WORDS] __attribute__((
    section(".isr_vector"))) = {STACK_POINTER_INIT_ADD,
                                (uintptr_t)&reset_handler,
                                (uintptr_t)&nmi_handler,
                                (uintptr_t)&hard_fault_handler,
                                (uintptr_t)&mem_manage_handler,
                                (uintptr_t)&bus_fault_handler,
                                (uintptr_t)&usage_fault_handler,
                                0,
                                (uintptr_t)&svcall_handler,
                                (uintptr_t)&debug_moniter_handler,
                                0,
                                (uintptr_t)&pendsv_handler,
                                (uintptr_t)&systick_handler,
                                (uintptr_t)&wwdg_handler,
                                (uintptr_t)&pvd_handler,
                                (uintptr_t)&tamp_stamp_handler,
                                (uintptr_t)&rtc_wkup_handler,
                                (uintptr_t)&flash_handler,
                                (uintptr_t)&rcc_handler,
                                (uintptr_t)&exti0_handler,
                                (uintptr_t)&exti1_handler,
                                (uintptr_t)&exti2_handler,
                                (uintptr_t)&exti3_handler,
                                (uintptr_t)&exti4_handler,
                                (uintptr_t)&dma1_stream0_handler,
                                (uintptr_t)&dma1_stream1_handler,
                                (uintptr_t)&dma1_stream2_handler,
                                (uintptr_t)&dma1_stream3_handler,
                                (uintptr_t)&dma1_stream4_handler,
                                (uintptr_t)&dma1_stream5_handler,
                                (uintptr_t)&dma1_stream6_handler,
                                (uintptr_t)&adc_handler,
                                (uintptr_t)&can1_tx_handler,
                                (uintptr_t)&can1_rx0_handler,
                                (uintptr_t)&can1_rx1_handler,
                                (uintptr_t)&can1_sce_handler,
                                (uintptr_t)&exti9_5_handler,
                                (uintptr_t)&tim1_brk_tim9_handler,
                                (uintptr_t)&tim1_up_tim10_handler,
                                (uintptr_t)&tim1_trg_com_tim11_handler,
                                (uintptr_t)&tim1_cc_handler,
                                (uintptr_t)&tim2_handler,
                                (uintptr_t)&tim3_handler,
                                (uintptr_t)&tim4_handler,
                                (uintptr_t)&i2c1_ev_handler,
                                (uintptr_t)&i2c1_er_handler,
                                (uintptr_t)&i2c2_ev_handler,
                                (uintptr_t)&i2c2_er_handler,
                                (uintptr_t)&spi1_handler,
                                (uintptr_t)&spi2_handler,
                                (uintptr_t)&usart1_handler,
                                (uintptr_t)&usart2_handler,
                                (uintptr_t)&usart3_handler,
                                (uintptr_t)&exti15_10_handler,
                                (uintptr_t)&rtc_alarm_handler,
                                (uintptr_t)&otg_fs_wkup_handler,
                                (uintptr_t)&tim8_brk_tim12_handler,
                                (uintptr_t)&tim8_up_tim13_handler,
                                (uintptr_t)&tim8_trg_com_tim14_handler,
                                (uintptr_t)&tim8_cc_handler,
                                (uintptr_t)&dma1_stream7_handler,
                                (uintptr_t)&fmc_handler,
                                (uintptr_t)&sdio_handler,
                                (uintptr_t)&tim5_handler,
                                (uintptr_t)&spi3_handler,
                                (uintptr_t)&uart4_handler,
                                (uintptr_t)&uart5_handler,
                                (uintptr_t)&tim5_dac_handler,
                                (uintptr_t)&tim7_handler,
                                (uintptr_t)&dma2_stream0_handler,
                                (uintptr_t)&dma2_stream1_handler,
                                (uintptr_t)&dma2_stream2_handler,
                                (uintptr_t)&dma2_stream3_handler,
                                (uintptr_t)&dma2_stream4_handler,
                                0,
                                0,
                                (uintptr_t)&can2_tx_handler,
                                (uintptr_t)&can2_rx0_handeler,
                                (uintptr_t)&can2_rx1_handler,
                                (uintptr_t)&can2_sce_handler,
                                (uintptr_t)&otg_fs_handler,
                                (uintptr_t)&dma2_stream5_handler,
                                (uintptr_t)&dma2_stream6_handler,
                                (uintptr_t)&dma2_stream7_handler,
                                (uintptr_t)&usart6_handler,
                                (uintptr_t)&i2c3_ev_handler,
                                (uintptr_t)&i2c3_er_handler,
                                (uintptr_t)&otg_hs_ep1_out_handler,
                                (uintptr_t)&otg_hs_ep1_in_handler,
                                (uintptr_t)&otg_hs_wkup_handler,
                                (uintptr_t)&otg_hs_handler,
                                (uintptr_t)&dcmi_handler,
                                0,
                                0,
                                (uintptr_t)&fpu_handler,
                                0,
                                0,
                                (uintptr_t)&spi4_handler,
                                0,
                                0,
                                (uintptr_t)&sai1_handler,
                                0,
                                0,
                                0,
                                (uintptr_t)&sai2_handler,
                                (uintptr_t)&quadspi_handler,
                                (uintptr_t)&hdmi_cec_handler,
                                (uintptr_t)&spdif_rx_handler,
                                (uintptr_t)&fmpi2c1_handler,
                                (uintptr_t)&fmpi2c1_error_handler};

void default_handler(void) {}

void reset_handler(void) {
  uint8_t *flash_data = (uint8_t *)&_etext;
  uint8_t *sram_data = (uint8_t *)&_sdata;
  uint32_t data_size = &_edata - &_sdata;
  for (int i = 0; i < data_size; i++) {
    sram_data[i] = flash_data[i];
  }

  uint8_t *bss = (uint8_t *)&_sbss;
  uint32_t bss_size = _ebss - _sbss;
  for (int i = 0; i < bss_size; i++) {
    bss[i] = 0;
  }

  main();
}

/********************************************************************
 * Copyright (C) 2009, 2012 by Verimag                              *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

/*!
  \file hal.h
  \brief Harwdare Abstraction Layer : implementation for MicroBlaze
  ISS.


*/
#ifndef HAL_H
#define HAL_H

#include <stdint.h>

#define hal_read32(a)      (*((uint32_t *)(a)))
#define hal_write32(a, d)  (*((uint32_t *)(a)) = (d))

extern volatile int irq_received;

void hal_cpu_relax() {
    // NOOP
}

void hal_wait_for_irq() {
    while (!irq_received) { hal_cpu_relax(); }
    irq_received = 0;
}


void microblaze_enable_interrupts(void) {
	__asm("ori     r3, r0, 2\n"
	      "mts     rmsr, r3");
}

#define printf hal_printf
void hal_printf(char *string){
    uint32_t base_addr = ((uint32_t) (string)) & ~0x3;
    uint32_t cur_word = hal_read32(base_addr);
    uint32_t cur_char = (cur_word & 0xFF000000) >> 24;
    uint32_t i = 0, j = 0;
    while (cur_char != '\0') {
        hal_write32(UART_BASEADDR + UART_FIFO_WRITE, cur_char);
        j++;
        if (j > 3) {
            j = 0;
            i++;
            cur_word = hal_read32(base_addr + 4 * i);
        }
        cur_char = (cur_word >> ((3 - j) * 8)) & 0xFF;
    }
}

#endif /* HAL_H */

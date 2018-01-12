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
#define hal_wait_for_irq() /* TODO */
#define hal_cpu_relax() /* TODO */

void microblaze_enable_interrupts(void) {
	__asm("ori     r3, r0, 2\n"
	      "mts     rmsr, r3");
}

/* TODO: printf is disabled, for now ... */
#define printf(...) do {} while(0)

#endif /* HAL_H */

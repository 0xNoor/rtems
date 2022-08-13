/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup bsp_interrupt
 *
 * @brief jmr3904 interrupt definitions.
 */

/*
 *  COPYRIGHT (c) 1989-2012.
 *  On-Line Applications Research Corporation (OAR).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LIBBSP_MIPS_JMR3904_IRQ_H
#define LIBBSP_MIPS_JMR3904_IRQ_H

#ifndef ASM
  #include <rtems.h>
  #include <rtems/irq.h>
  #include <rtems/irq-extension.h>
  #include <rtems/score/mips.h>
#endif

/**
 * @addtogroup bsp_interrupt
 *
 * @{
 */

/*
 *  Interrupt Vector Numbers
 *
 *  NOTE: Numbers 0-15 directly map to levels on the IRC.
 *        Number 16 is "1xxxx" per p. 164 of the TX3904 manual.
 */

  #define TX3904_IRQ_INT1        MIPS_INTERRUPT_BASE+0
  #define TX3904_IRQ_INT2        MIPS_INTERRUPT_BASE+1
  #define TX3904_IRQ_INT3        MIPS_INTERRUPT_BASE+2
  #define TX3904_IRQ_INT4        MIPS_INTERRUPT_BASE+3
  #define TX3904_IRQ_INT5        MIPS_INTERRUPT_BASE+4
  #define TX3904_IRQ_INT6        MIPS_INTERRUPT_BASE+5
  #define TX3904_IRQ_INT7        MIPS_INTERRUPT_BASE+6
  #define TX3904_IRQ_DMAC3       MIPS_INTERRUPT_BASE+7
  #define TX3904_IRQ_DMAC2       MIPS_INTERRUPT_BASE+8
  #define TX3904_IRQ_DMAC1       MIPS_INTERRUPT_BASE+9
  #define TX3904_IRQ_DMAC0       MIPS_INTERRUPT_BASE+10
  #define TX3904_IRQ_SIO0        MIPS_INTERRUPT_BASE+11
  #define TX3904_IRQ_SIO1        MIPS_INTERRUPT_BASE+12
  #define TX3904_IRQ_TMR0        MIPS_INTERRUPT_BASE+13
  #define TX3904_IRQ_TMR1        MIPS_INTERRUPT_BASE+14
  #define TX3904_IRQ_TMR2        MIPS_INTERRUPT_BASE+15
  #define TX3904_IRQ_INT0        MIPS_INTERRUPT_BASE+16
  #define TX3904_IRQ_SOFTWARE_1  MIPS_INTERRUPT_BASE+17
  #define TX3904_IRQ_SOFTWARE_2  MIPS_INTERRUPT_BASE+18
  #define TX3904_MAXIMUM_VECTORS MIPS_INTERRUPT_BASE+19

#define BSP_INTERRUPT_VECTOR_COUNT (TX3904_MAXIMUM_VECTORS + 1)

/** @} */

#endif /* LIBBSP_MIPS_JMR3904_IRQ_H */

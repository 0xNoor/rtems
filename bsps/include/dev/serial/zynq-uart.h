/**
 * @file
 * @ingroup zynq_uart
 * @brief UART support.
 */

/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2013, XXX embedded brains GmbH & Co. KG
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

#ifndef LIBBSP_ARM_XILINX_ZYNQ_UART_H
#define LIBBSP_ARM_XILINX_ZYNQ_UART_H

#include <rtems/termiostypes.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup zynq_uart UART Support
 * @ingroup RTEMSBSPsARMZynq
 * @brief UART Support
 *
 * This driver operates an instance of the Cadence UART present in the
 * family of Xilinx Zynq SoCs.
 */

typedef struct {
  rtems_termios_device_context base;
  volatile struct zynq_uart *regs;
  int tx_queued;
  bool transmitting;
  rtems_vector_number irq;
} zynq_uart_context;

extern const rtems_termios_device_handler zynq_uart_handler;

#define ZYNQ_UART_DEFAULT_BAUD 115200

void zynq_uart_initialize(rtems_termios_device_context *base);

int zynq_uart_read_polled(rtems_termios_device_context *base);

void zynq_uart_write_polled(
  rtems_termios_device_context *base,
  char c
);

/**
  * Flush TX FIFO and wait until it is empty. Used in bsp_reset.
  */
void zynq_uart_reset_tx_flush(zynq_uart_context *ctx);

int zynq_cal_baud_rate(
  uint32_t  baudrate,
  uint32_t* brgr,
  uint32_t* bauddiv,
  uint32_t  modereg
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIBBSP_ARM_XILINX_ZYNQ_UART_H */

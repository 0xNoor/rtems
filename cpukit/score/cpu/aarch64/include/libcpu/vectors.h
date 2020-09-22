/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup RTEMSScoreCPUAArch64
 *
 * @brief ARM AArch64 Exception API.
 */

/*
 * Copyright (C) 2020 On-Line Applications Research Corporation (OAR)
 * Written by Kinsey Moore <kinsey.moore@oarcorp.com>
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

#ifndef LIBCPU_AARCH64_VECTORS_H
#define LIBCPU_AARCH64_VECTORS_H

#ifndef ASM

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* VBAR, Vector Base Address Register, Security Extensions */

static inline void
*AArch64_get_vector_base_address(void)
{
  void *base;

  __asm__ volatile (
    "mrs %[base], VBAR_EL1\n"
    : [base] "=&r" (base)
  );

  return base;
}

static inline void
AArch64_set_vector_base_address(void *base)
{
  __asm__ volatile (
    "msr VBAR_EL1, %[base]\n"
    : : [base] "r" (base)
  );
}

static inline void
*AArch64_get_hyp_vector_base_address(void)
{
  void *base;

  __asm__ volatile (
    "mrs %[base], VBAR_EL2\n"
    : [base] "=&r" (base)
  );

  return base;
}

static inline void
AArch64_set_hyp_vector_base_address(void *base)
{
  __asm__ volatile (
    "msr VBAR_EL2, %[base]\n"
    : : [base] "r" (base)
  );
}

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ASM */

#endif /* LIBCPU_AARCH64_VECTORS_H */

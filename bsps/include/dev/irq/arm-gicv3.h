/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup arm_gic
 *
 * @brief This header file contains interfaces to access an Arm GICv3.
 */

/*
 * Copyright (C) 2022 embedded brains GmbH (http://www.embedded-brains.de)
 * Copyright (C) 2019 On-Line Applications Research Corporation (OAR)
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

#ifndef _RTEMS_DEV_IRQ_ARM_GICV3_H
#define _RTEMS_DEV_IRQ_ARM_GICV3_H

#include <dev/irq/arm-gic.h>
#include <dev/irq/arm-gic-arch.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PRIORITY_DEFAULT 127

#define MPIDR_AFFINITY2(val) BSP_FLD64(val, 16, 23)
#define MPIDR_AFFINITY2_GET(reg) BSP_FLD64GET(reg, 16, 23)
#define MPIDR_AFFINITY2_SET(reg, val) BSP_FLD64SET(reg, val, 16, 23)
#define MPIDR_AFFINITY1(val) BSP_FLD64(val, 8, 15)
#define MPIDR_AFFINITY1_GET(reg) BSP_FLD64GET(reg, 8, 15)
#define MPIDR_AFFINITY1_SET(reg, val) BSP_FLD64SET(reg, val, 8, 15)
#define MPIDR_AFFINITY0(val) BSP_FLD64(val, 0, 7)
#define MPIDR_AFFINITY0_GET(reg) BSP_FLD64GET(reg, 0, 7)
#define MPIDR_AFFINITY0_SET(reg, val) BSP_FLD64SET(reg, val, 0, 7)

#define ICC_SGIR_AFFINITY3(val) BSP_FLD64(val, 48, 55)
#define ICC_SGIR_AFFINITY3_GET(reg) BSP_FLD64GET(reg, 48, 55)
#define ICC_SGIR_AFFINITY3_SET(reg, val) BSP_FLD64SET(reg, val, 48, 55)
#define ICC_SGIR_IRM BSP_BIT32(40)
#define ICC_SGIR_AFFINITY2(val) BSP_FLD64(val, 32, 39)
#define ICC_SGIR_AFFINITY2_GET(reg) BSP_FLD64GET(reg, 32, 39)
#define ICC_SGIR_AFFINITY2_SET(reg, val) BSP_FLD64SET(reg, val, 32, 39)
#define ICC_SGIR_INTID(val) BSP_FLD64(val, 24, 27)
#define ICC_SGIR_INTID_GET(reg) BSP_FLD64GET(reg, 24, 27)
#define ICC_SGIR_INTID_SET(reg, val) BSP_FLD64SET(reg, val, 24, 27)
#define ICC_SGIR_AFFINITY1(val) BSP_FLD64(val, 16, 23)
#define ICC_SGIR_AFFINITY1_GET(reg) BSP_FLD64GET(reg, 16, 23)
#define ICC_SGIR_AFFINITY1_SET(reg, val) BSP_FLD64SET(reg, val, 16, 23)
#define ICC_SGIR_CPU_TARGET_LIST(val) BSP_FLD64(val, 0, 15)
#define ICC_SGIR_CPU_TARGET_LIST_GET(reg) BSP_FLD64GET(reg, 0, 15)
#define ICC_SGIR_CPU_TARGET_LIST_SET(reg, val) BSP_FLD64SET(reg, val, 0, 15)

#ifdef ARM_MULTILIB_ARCH_V4
/* cpuif->iccicr */
#define ICC_CTLR    "p15, 0, %0, c12, c12, 4"

/* cpuif->iccpmr */
#define ICC_PMR     "p15, 0, %0,  c4,  c6, 0"

/* cpuif->iccbpr */
#define ICC_BPR0    "p15, 0, %0, c12,  c8, 3"
#define ICC_BPR1    "p15, 0, %0, c12, c12, 3"

/* cpuif->icciar */
#define ICC_IAR0    "p15, 0, %0, c12,  c8, 0"
#define ICC_IAR1    "p15, 0, %0, c12, c12, 0"

/* cpuif->icceoir */
#define ICC_EOIR0   "p15, 0, %0, c12,  c8, 1"
#define ICC_EOIR1   "p15, 0, %0, c12, c12, 1"

#define ICC_SRE     "p15, 0, %0, c12, c12, 5"

#define ICC_IGRPEN0 "p15, 0, %0, c12, c12, 6"
#define ICC_IGRPEN1 "p15, 0, %0, c12, c12, 7"

#define MPIDR       "p15, 0, %0, c0, c0, 5"

#define READ_SR(SR_NAME) \
({ \
  uint32_t value; \
  __asm__ volatile("mrc    " SR_NAME : "=r" (value) ); \
  value; \
})

#define WRITE_SR(SR_NAME, VALUE) \
    __asm__ volatile("mcr    " SR_NAME "  \n" : : "r" (VALUE) );

#define ICC_SGI1    "p15, 0, %Q0, %R0, c12"
#define WRITE64_SR(SR_NAME, VALUE) \
    __asm__ volatile("mcrr    " SR_NAME "  \n" : : "r" (VALUE) );

#else /* ARM_MULTILIB_ARCH_V4 */

/* AArch64 GICv3 registers are not named in GCC */
#define ICC_IGRPEN0 "S3_0_C12_C12_6, %0"
#define ICC_IGRPEN1 "S3_0_C12_C12_7, %0"
#define ICC_IGRPEN1_EL3 "S3_6_C12_C12_7, %0"
#define ICC_PMR     "S3_0_C4_C6_0, %0"
#define ICC_EOIR1   "S3_0_C12_C12_1, %0"
#define ICC_SRE     "S3_0_C12_C12_5, %0"
#define ICC_BPR0    "S3_0_C12_C8_3, %0"
#define ICC_CTLR    "S3_0_C12_C12_4, %0"
#define ICC_IAR1    "%0, S3_0_C12_C12_0"
#define MPIDR       "%0, mpidr_el1"
#define MPIDR_AFFINITY3(val) BSP_FLD64(val, 32, 39)
#define MPIDR_AFFINITY3_GET(reg) BSP_FLD64GET(reg, 32, 39)
#define MPIDR_AFFINITY3_SET(reg, val) BSP_FLD64SET(reg, val, 32, 39)

#define ICC_SGI1    "S3_0_C12_C11_5, %0"
#define WRITE64_SR(SR_NAME, VALUE) \
    __asm__ volatile("msr    " SR_NAME "  \n" : : "r" (VALUE) );
#define WRITE_SR(SR_NAME, VALUE) WRITE64_SR(SR_NAME, VALUE)

#define READ_SR(SR_NAME) \
({ \
  uint64_t value; \
  __asm__ volatile("mrs    " SR_NAME : "=&r" (value) ); \
  value; \
})

#endif /* ARM_MULTILIB_ARCH_V4 */

static inline volatile gic_redist *gicv3_get_redist(uint32_t cpu_index)
{
  return (volatile gic_redist *)
    ((uintptr_t)BSP_ARM_GIC_REDIST_BASE + cpu_index * 0x20000);
}

static inline volatile gic_sgi_ppi *gicv3_get_sgi_ppi(uint32_t cpu_index)
{
  return (volatile gic_sgi_ppi *)
    ((uintptr_t)BSP_ARM_GIC_REDIST_BASE + cpu_index * 0x20000 + 0x10000);
}

static inline void gicv3_sgi_ppi_enable(
  rtems_vector_number vector,
  uint32_t            cpu_index
)
{
  volatile gic_sgi_ppi *sgi_ppi = gicv3_get_sgi_ppi(cpu_index);

  /* Set G1NS */
  sgi_ppi->icspigrpr[0] |= 1U << vector;
  sgi_ppi->icspigrpmodr[0] &= ~(1U << vector);

  /* Set enable */
  sgi_ppi->icspiser[0] = 1U << vector;
}

static inline bool gicv3_sgi_ppi_is_enabled(
  rtems_vector_number vector,
  uint32_t            cpu_index
)
{
  volatile gic_sgi_ppi *sgi_ppi = gicv3_get_sgi_ppi(cpu_index);

  return (sgi_ppi->icspiser[0] & (1U << vector)) != 0;
}

static inline bool gicv3_sgi_ppi_is_pending(
  rtems_vector_number vector,
  uint32_t            cpu_index
)
{
  volatile gic_sgi_ppi *sgi_ppi = gicv3_get_sgi_ppi(cpu_index);

  return (sgi_ppi->icspispendr[0] & (1U << vector)) != 0;
}

static inline void gicv3_ppi_set_pending(
  rtems_vector_number vector,
  uint32_t            cpu_index
)
{
  volatile gic_sgi_ppi *sgi_ppi = gicv3_get_sgi_ppi(cpu_index);

  sgi_ppi->icspispendr[0] = 1U << vector;
}

static inline void gicv3_ppi_clear_pending(
  rtems_vector_number vector,
  uint32_t            cpu_index
)
{
  volatile gic_sgi_ppi *sgi_ppi = gicv3_get_sgi_ppi(cpu_index);

  sgi_ppi->icspicpendr[0] = 1U << vector;
}

static inline void gicv3_trigger_sgi(
  rtems_vector_number vector,
  uint32_t            targets
)
{
#ifndef ARM_MULTILIB_ARCH_V4
  uint64_t mpidr;
#else
  uint32_t mpidr;
#endif
  mpidr = READ_SR(MPIDR);
  uint64_t value = ICC_SGIR_AFFINITY2(MPIDR_AFFINITY2_GET(mpidr))
                 | ICC_SGIR_INTID(vector)
                 | ICC_SGIR_AFFINITY1(MPIDR_AFFINITY1_GET(mpidr))
                 | ICC_SGIR_CPU_TARGET_LIST(targets);
#ifndef ARM_MULTILIB_ARCH_V4
  value |= ICC_SGIR_AFFINITY3(MPIDR_AFFINITY3_GET(mpidr));
#endif
  WRITE64_SR(ICC_SGI1, value);
}

#ifdef __cplusplus
}
#endif

#endif /* _RTEMS_DEV_IRQ_ARM_GICV3_H */

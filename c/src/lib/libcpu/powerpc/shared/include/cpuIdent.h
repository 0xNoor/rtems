/*
 * Copyright (C) 1999  Eric Valette (valette@crf.canon.fr)
 *                     Canon Centre Recherche France.
 *
 *  Added MPC8260 Andy Dachs <a.dachs@sstl.co.uk>
 *  Surrey Satellite Technology Limited
 *
 *
 *  The license and distribution terms for this file may be
 *  found in found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#ifndef _libcpu_cpuIdent_h
#define _libcpu_cpuIdent_h

#ifndef ASM
typedef enum
{
  PPC_601 = 0x1,
  PPC_5XX = 0x2,
  PPC_509 = PPC_5XX,
  PPC_533 = PPC_5XX,
  PPC_534 = PPC_5XX,
  PPC_535 = PPC_5XX,
  PPC_536 = PPC_5XX,
  PPC_555 = PPC_5XX,
  PPC_556 = PPC_5XX,
  PPC_561 = PPC_5XX,
  PPC_562 = PPC_5XX,
  PPC_563 = PPC_5XX,
  PPC_564 = PPC_5XX,
  PPC_565 = PPC_5XX,
  PPC_566 = PPC_5XX,
  MPC_5XX = PPC_5XX,
  PPC_603 = 0x3,
  PPC_604 = 0x4,
  PPC_603e = 0x6,
  PPC_603ev = 0x7,
  PPC_750 = 0x8,
  PPC_604e = 0x9,
  PPC_604r = 0xA,
  PPC_7400 = 0xC,
  PPC_620 = 0x16,
  PPC_860 = 0x50,
  PPC_821 = PPC_860,
  PPC_823 = PPC_860,
  PPC_8260 = 0x81,
  PPC_UNKNOWN = 0xff
} ppc_cpu_id_t;

typedef unsigned short ppc_cpu_revision_t;

extern ppc_cpu_id_t get_ppc_cpu_type ();
extern ppc_cpu_id_t current_ppc_cpu;
extern char *get_ppc_cpu_type_name(ppc_cpu_id_t cpu);
extern ppc_cpu_revision_t get_ppc_cpu_revision ();
extern ppc_cpu_revision_t current_ppc_revision;
#endif /* ASM */

#endif

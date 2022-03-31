/* SPDX-License-Identifier: BSD-2-Clause */

/*  system.h
 *
 *  This include file contains information that is included in every
 *  function in the test set.
 *
 *  COPYRIGHT (c) 1989-2009.
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

#include <tmacros.h>

/* functions */

rtems_task Init(
  rtems_task_argument argument
);

rtems_task Task_1(
  rtems_task_argument argument
);

rtems_task Task_2(
  rtems_task_argument argument
);

rtems_task Task_3(
  rtems_task_argument argument
);

rtems_task Task_4(
  rtems_task_argument argument
);

rtems_task Task5(
  rtems_task_argument argument
);

/* configuration information */

#define CONFIGURE_APPLICATION_NEEDS_SIMPLE_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_TASKS               4
#define CONFIGURE_MAXIMUM_REGIONS             4
#define CONFIGURE_TICKS_PER_TIMESLICE       100

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_EXTRA_TASK_STACKS         (1 * RTEMS_MINIMUM_STACK_SIZE)

#include <rtems/confdefs.h>

/* global variables */

TEST_EXTERN rtems_id   Task_id[ 6 ];      /* array of task ids */
TEST_EXTERN rtems_name Task_name[ 6 ];    /* array of task names */
TEST_EXTERN rtems_id   Region_id[ 5 ];    /* array of region ids */
TEST_EXTERN rtems_name Region_name[ 5 ];  /* array of region names */

TEST_EXTERN uint8_t   Area_1[4096] CPU_STRUCTURE_ALIGNMENT;
TEST_EXTERN uint8_t   Area_2[4096] CPU_STRUCTURE_ALIGNMENT;
TEST_EXTERN uint8_t   Area_3[4096] CPU_STRUCTURE_ALIGNMENT;
TEST_EXTERN uint8_t   Area_4[8192] CPU_STRUCTURE_ALIGNMENT;

#define BASE_PRIORITY ((RTEMS_MAXIMUM_PRIORITY / 2u) + 1u)

#define Put_address_from_area_1( _to_be_printed ) \
   printf( "0x%08lx", \
     (unsigned long) ((uint8_t   *)(_to_be_printed) - Area_1 ) )

#define Put_address_from_area_2( _to_be_printed ) \
   printf( "0x%08lx", \
     (unsigned long) ((uint8_t   *)(_to_be_printed) - Area_2 ) )

#define Put_address_from_area_3( _to_be_printed ) \
   printf( "0x%08lx", \
     (unsigned long) ((uint8_t   *)(_to_be_printed) - Area_3 ) )

#define Put_address_from_area_4( _to_be_printed ) \
   printf( "0x%08lx", \
     (unsigned long) ((uint8_t   *)(_to_be_printed) - Area_4 ) )

/* end of include file */

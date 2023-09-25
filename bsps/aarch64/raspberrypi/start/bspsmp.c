#include <rtems/score/smpimpl.h>
#include <bsp/raspberrypi.h>

#include <bsp/irq.h>

static uint32_t cpu_addr[] =
{
    [0] = 0xd8,
    [1] = 0xe0,
    [2] = 0xe8,
    [3] = 0xf0,
    [4] = 0x00
};


bool _CPU_SMP_Start_processor( uint32_t cpu_index )
{
  bool started;
  uint32_t cpu_index_self = _SMP_Get_current_processor();

  if (cpu_index != cpu_index_self) {

    //__asm__ volatile ("str %0, [%1]"::"rZ"((uint32_t)_start), "r"(cpu_addr[cpu_index]));
    BCM2711_REG(cpu_addr[cpu_index]) = (uint32_t)_start;
    _AARCH64_Send_event();
    printf("i am %x  \n", (cpu_addr[cpu_index] ));
    _AARCH64_Data_synchronization_barrier();
  } else {
    started = false;
  }
  return started;
}




uint32_t _CPU_SMP_Initialize(void)
{
  return 4;
}

void _CPU_SMP_Finalize_initialization( uint32_t cpu_count )
{
  /* Do nothing */
}

void _CPU_SMP_Prepare_start_multitasking( void )
{
  /* Do nothing */
}

void _CPU_SMP_Send_interrupt( uint32_t target_cpu_index )
{
  /* Generates IPI */

}
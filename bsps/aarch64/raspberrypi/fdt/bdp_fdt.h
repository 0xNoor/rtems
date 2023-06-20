#include <bsp.h>
#include <bsp/fdt.h>

const void *bsp_fdt_get(void)
{
  return rpi4b_dtb;
}

uint32_t bsp_fdt_map_intr(const uint32_t *intr, size_t icells)
{
  if (icells != 3) {
    return 0;
  }
  return (intr[0] == 0 ? 32 : 16) + intr[1];
}
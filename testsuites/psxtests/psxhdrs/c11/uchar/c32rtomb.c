/**
 *  @file
 *  @brief c32rtomb() API Conformance Test. This is a C11 method.
 */

/*
 *  COPYRIGHT (c) 2018.
 *  Marçal Comajoan Cara
 *
 *  Permission to use, copy, modify, and/or distribute this software
 *  for any purpose with or without fee is hereby granted.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 *  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
 *  BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
 *  OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 *  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 *  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <uchar.h>
#include <stdlib.h>

int test( void );

int test( void )
{
  char32_t* c32_str = U"Mar\u00E7al";
  char out[MB_CUR_MAX];
  mbstate_t mbs;
  int result;

  result = c32rtomb( out, *c32_str, &mbs );

  return result;
}

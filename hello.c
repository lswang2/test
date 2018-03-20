#include "sysdep.h"
#include <stdio.h>
#include "bfd.h"
#include "opcode/arc.h"
#include "opintl.h"
#include "libiberty.h"

/* Insert RA register into a 32-bit opcode, with checks.  */

static unsigned long long
insert_ra_chk (unsigned long long  insn,
	       long long           value,
	       const char **       errmsg)
{
  if (value == 60)
    *errmsg = _("LP_COUNT register cannot be used as destination register");

  return insn | (value & 0x3F);
}

#include "sysdep.h"
#include <stdio.h>
#include "bfd.h"
#include "opcode/arc.h"
#include "opintl.h"
#include "libiberty.h"

/* ARC NPS400 Support: The ARC NPS400 core is an ARC700 with some custom
   instructions. All NPS400 features are built into all ARC target builds as
   this reduces the chances that regressions might creep in.  */

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

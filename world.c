/* Insert RB register into a 32-bit opcode.  */

static unsigned long long
insert_rb (unsigned long long  insn,
	   long long           value,
	   const char **       errmsg ATTRIBUTE_UNUSED)
{
  return insn | ((value & 0x07) << 24) | (((value >> 3) & 0x07) << 12);
}

/* Insert RB register with checks.  */

static unsigned long long
insert_rb_chk (unsigned long long  insn,
	       long long           value,
	       const char **       errmsg)
{
  if (value == 60)
    *errmsg = _("LP_COUNT register cannot be used as destination register");

  return insn | ((value & 0x07) << 24) | (((value >> 3) & 0x07) << 12);
}

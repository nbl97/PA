#include "cpu/exec/template-start.h"

#define instr movsx

static void do_execute() {
	DATA_TYPE_S src = (int8_t)(op_src->val & 0xff);
	OPERAND_W(op_dest, src);
	print_asm_template2();
}

make_helper(concat(movsx_, SUFFIX)) {
	return idex(eip, concat(decode_rm2r_, b), do_execute);
}

make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"

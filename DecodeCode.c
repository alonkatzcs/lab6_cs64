#include "DecodeCode.h"
#include "stdio.h"
#include "stdlib.h"

mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = value & 0x3F;
	if (value >> 15 & 1 == 1){	
		int temp = (value ^ 0xFFFF) + 1;
		instr.immediate = -(temp&0x7FFF);		
	} else {
		instr.immediate = value & 0x7FFF;
	}
	instr.rd = value >> 11 & 0x1F;
	instr.rt = value >> 16 & 0x1F;
	instr.rs = value >> 21 & 0x1F;
	instr.opcode = value >> 26 & 0x3F;

	return instr;
}



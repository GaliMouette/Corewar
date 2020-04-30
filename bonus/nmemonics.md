|Mnemonic|Effects|
|:----------:| -----------------------------------------------------------|
|0x01 (live)| takes 1 parameter: 4 bytes that represent the player’s number. It indicates that the player is alive.|
|0x02 (ld)| takes 2 parameters. It loads the value of the first parameter into the second parameter, which must be a register (not the PC). This operation modifies the carry. ld 34,r3 loads the REG_SIZE bytes starting at the address PC + 34 % IDX_MOD into r3.|
|0x03 (st)| takes 2 parameters. It stores the first parameter’s value (which is a register) into the second (whether a register or a number). st r4,34 stores the content of r4 at the address PC + 34 % IDX_MOD. st r3,r8 copies the content of r3 into r8.|
|0x04 (add)| takes 3 registers as parameters. It adds the content of the first two and puts the sum into the third one (which must be a register). This operation modifies the carry. add r2,r3,r5 adds the content of r2 and r3 and puts the result into r5.|
|0x05 (sub)| Similar to add, but performing a subtraction.|
|0x06 (and)| takes 3 parameters. It performs a binary AND between the first two parameters and stores the result into the third one (which must be a register). This operation modifies the carry. and r2, %0,r3 puts r2 & 0 into r3.|
|0x07 (or)| Similar to and, but performing a binary OR.|
|0x08 (xor)| Similar to and, but performing a binary XOR (exclusive OR).|
|0x09 (zjmp)| takes 1 parameter, which must be an index. It jumps to this index if the carry is worth 1. Otherwise, it does nothing but consumes the same time. zjmp %23 puts, if carry equals 1, PC + 23 % IDX_MOD into the PC.|
|0x0a (ldi)| takes 3 parameters. The first two must be indexes, the third one must be a register. This operation modifies the carry. ldi 3,%4,r1 reads IND_SIZ bytes from the address PC + 3 % IDX_MOD, adds 4 to this value. The sum is named S. REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1.|
|0x0b (sti)| takes 3 parameters. The first one must be a register. The other two can be indexes or registers. sti r2,%4,%5 copies the content of r2 into the address PC + (4+5)% IDX_MOD.|
|0x0c (fork)| takes 1 parameter, which must be an index. It creates a new program that inherits different states from the parent. This program is executed at the address PC + first parameter % IDX_MOD.|
|0x0d (lld)| Similar to ld without the % IDX_MOD. This operation modifies the carry.|
|0x0e (lldi)| Similar to ldi without the % IDX_MOD. This operation modifies the carry.|
|0x0f (lfork)| Similar to fork without the % IDX_MOD.|
|0x10 (aff)| takes 1 parameter, which must be a register. It displays on the standard output the character whose ASCII code is the content of the register (in base 10). A 256 modulo is applied to this ASCII code. aff r3 displays ’*’ if r3 contains 42.|

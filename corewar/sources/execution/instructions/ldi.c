/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ldi_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int ldi_instruction(arena_t *arena, int i)
{
    int term1, term2;
    int result;
    int address;

    set_term(&term1, arena, i, 0);
    set_term(&term2, arena, i, 1);
    result = term1 + term2;
    address = arena->execs[i]->pc + result % IDX_MOD;
    address %= MEM_SIZE;
    get_indirect_value(arena, address, REG_SIZE, &result);
    arena->execs[i]->carry = 1;
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] = result;
    return 0;
}

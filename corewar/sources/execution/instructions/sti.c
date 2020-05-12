/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** sti
*/

#include "corewar/execution/instructions/instructions.h"

int sti(arena_t *arena, int i)
{
    int term1,term2;
    int sum;
    int result =
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[0] - 1];
    int address;

    set_opterm(&term1, arena, i, 1);
    set_opterm(&term2, arena, i, 2);
    sum = term1 + term2;
    address = arena->execs[i]->pc + sum % IDX_MOD;
    address %= MEM_SIZE;
    set_indirect_value(arena, address, REG_SIZE, result);
    return 0;
}

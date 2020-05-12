/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ld
*/

#include "corewar/execution/instructions/instructions.h"

int ld(arena_t *arena, int i)
{
    int result;
    loaded_op_t loaded_op = arena->execs[i]->loaded_op;
    int address = arena->execs[i]->pc + loaded_op.args[0] % IDX_MOD;

    address %= MEM_SIZE;
    get_indirect_value(arena, address, REG_SIZE, &result);
    arena->execs[i]->carry = 1;
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1] = result;
    return 0;
}

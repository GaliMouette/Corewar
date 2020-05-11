/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ld
*/

#include "corewar/execution/instructions/ld.h"

int ld(arena_t *arena, int i)
{
    int result;

    if (arena->execs[i]->loaded_op.args_type[0] == IND_TYPE) {
        read_in_memory(arena->memory, (arena->execs[i]->pc
        + arena->execs[i]->loaded_op.args[0]) % IDX_MOD, REG_SIZE, &result);
    } else {
        result = arena->execs[i]->loaded_op.args[0];
    } if (result) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1] = result;
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** st
*/

#include "corewar/execution/instructions/instructions.h"

int st(arena_t *arena, int i)
{
    int result =
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[0] - 1];

    if (arena->execs[i]->loaded_op.args_type[1] == REG_TYPE) {
        arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1]
        = result;
    } else {
        set_indirect_value(arena, (arena->execs[i]->pc
        + arena->execs[i]->loaded_op.args[1]) % IDX_MOD, REG_SIZE, result);
    }
    return 0;
}

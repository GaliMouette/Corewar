/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** lld
*/

#include "corewar/execution/instructions/instructions.h"

int lld(arena_t *arena, int i)
{
    int result;

    get_indirect_value(arena, (arena->execs[i]->pc
    + arena->execs[i]->loaded_op.args[0]), REG_SIZE, &result);
    if (result) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1] = result;
    return 0;
}

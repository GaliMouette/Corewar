/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** zjmp
*/

#include "corewar/execution/instructions/instructions.h"

int zjmp(arena_t *arena, int i)
{
    if (arena->execs[i]->carry) {
        arena->execs[i]->pc += arena->execs[i]->loaded_op.args[0] % IDX_MOD;
    }
    return 1;
}

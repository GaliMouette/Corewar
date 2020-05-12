/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** zjmp_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int zjmp_instruction(arena_t *arena, int i)
{
    if (arena->execs[i]->carry) {
        arena->execs[i]->pc += arena->execs[i]->loaded_op.args[0] % IDX_MOD;
    }
    arena->execs[i] = 0;
    return 1;
}

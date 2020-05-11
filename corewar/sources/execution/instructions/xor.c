/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** xor
*/

#include "corewar/execution/instructions/xor.h"

int xor(arena_t *arena, int i)
{
    int term1, term2;
    int result;

    set_operation_terms(&term1, &term2, arena, i);
    result = term1 ^ term2;
    if (result) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] = result;
    return 0;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** sub
*/

#include "corewar/execution/instructions/sub.h"

int sub(arena_t *arena, int i)
{
    int term1 =
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[0] - 1];
    int term2 =
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1];
    int difference = term1 - term2;

    if (difference) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] =
    difference;
    return 0;
}

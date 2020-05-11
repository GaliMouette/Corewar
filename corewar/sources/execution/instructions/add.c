/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add
*/

#include "corewar/execution/instructions/add.h"

int add(arena_t *arena, int i)
{
    int term1 =
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[0] - 1];
    int term2 =
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1];
    int sum = term1 + term2;

    if (sum) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] = sum;
    return 0;
}

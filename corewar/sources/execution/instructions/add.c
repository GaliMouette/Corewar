/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int add_instruction(arena_t *arena, int i)
{
    int term1, term2;
    long sum;
    int index = arena->execs[i]->loaded_op.args[2] - 1;

    set_term(&term1, arena, i, 0);
    set_term(&term2, arena, i, 1);
    sum = term1 + term2;
    if (sum < INT_MIN || INT_MAX < sum) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[index] = (int) sum;
    return 0;
}

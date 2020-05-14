/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** sub_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int sub_instruction(arena_t *arena, int i)
{
    int term1, term2;
    long diff;
    int index = arena->execs[i]->loaded_op.args[2] - 1;

    set_term(&term1, arena, i, 0);
    set_term(&term2, arena, i, 1);
    diff = term1 - term2;
    if (diff < INT_MIN || INT_MAX < diff) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[index] = (int) diff;
    return 0;
}

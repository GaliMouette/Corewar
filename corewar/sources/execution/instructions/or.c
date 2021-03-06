/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** or_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int or_instruction(arena_t *arena, int i)
{
    int term1, term2;
    int result;

    set_term(&term1, arena, i, 0);
    set_term(&term2, arena, i, 1);
    result = term1 | term2;
    arena->execs[i]->carry = 1;
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] = result;
    return 0;
}

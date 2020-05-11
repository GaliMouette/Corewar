/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** lldi
*/

#include "corewar/execution/instructions/instructions.h"

int lldi(arena_t *arena, int i)
{
    int term1, term2;
    int result;

    set_opterm(&term1, arena, i, 0);
    set_opterm(&term2, arena, i, 1);
    result = term1 + term2;
    get_indirect_value(arena, (arena->execs[i]->pc + result),
    REG_SIZE, &result);
    if (result) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] = result;
    return 0;
}

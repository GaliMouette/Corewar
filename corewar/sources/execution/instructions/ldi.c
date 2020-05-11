/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ldi
*/

#include "corewar/execution/instructions/ldi.h"

int ldi(arena_t *arena, int i)
{
    int term1, term2;
    int result;

    set_operation_terms(&term1, &term2, arena, i);
    result = term1 + term2;
    read_in_memory(arena->memory, (arena->execs[i]->pc + result) % IDX_MOD,
    REG_SIZE, &result);
    if (result) {
        arena->execs[i]->carry = 0;
    } else {
        arena->execs[i]->carry = 1;
    }
    arena->execs[i]->registry[arena->execs[i]->loaded_op.args[2] - 1] = result;
    return 0;
}

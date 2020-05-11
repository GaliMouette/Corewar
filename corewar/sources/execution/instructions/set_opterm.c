/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_operation
*/

#include "corewar/execution/instructions/set_opterm.h"

void set_opterm(int *term, arena_t *arena, int i, int j)
{
    if (arena->execs[i]->loaded_op.args_type[j] == REG_TYPE) {
        *term =
        arena->execs[i]->registry[arena->execs[i]->loaded_op.args[j] - 1];
    } else if (arena->execs[i]->loaded_op.args_type[j] == IND_TYPE) {
        get_indirect_value(arena, (arena->execs[i]->pc
        + arena->execs[i]->loaded_op.args[j]) % IDX_MOD, IND_SIZE, term);
    } else {
        *term = arena->execs[i]->loaded_op.args[j];
    }
}

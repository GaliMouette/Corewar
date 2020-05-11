/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_operation
*/

#include "corewar/execution/instructions/set_operation_terms.h"

void set_operation_terms(int *term1, int *term2, arena_t *arena, int i)
{
    if (arena->execs[i]->loaded_op.args_type[0] == REG_TYPE) {
        *term1 =
        arena->execs[i]->registry[arena->execs[i]->loaded_op.args[0] - 1];
    } else if (arena->execs[i]->loaded_op.args_type[0] == IND_TYPE) {
        read_in_memory(arena->memory, (arena->execs[i]->pc
        + arena->execs[i]->loaded_op.args[0]) % IDX_MOD, IND_SIZE, term1);
    } else {
        *term1 = arena->execs[i]->loaded_op.args[0];
    } if (arena->execs[i]->loaded_op.args_type[1] == REG_TYPE) {
        *term2 =
        arena->execs[i]->registry[arena->execs[i]->loaded_op.args[1] - 1];
    } else if (arena->execs[i]->loaded_op.args_type[1] == IND_TYPE) {
        read_in_memory(arena->memory, (arena->execs[i]->pc
        + arena->execs[i]->loaded_op.args[1]) % IDX_MOD, IND_SIZE, term2);
    } else {
        *term2 = arena->execs[i]->loaded_op.args[1];
    }
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_operation
*/

#include "corewar/execution/instructions/set_opterm.h"

void set_opterm(int *term, arena_t *arena, int i, int j)
{
    loaded_op_t loaded_op = arena->execs[i]->loaded_op;
    int address = arena->execs[i]->pc + loaded_op.args[j] % IDX_MOD;

    address %= MEM_SIZE;
    if (loaded_op.args_type[j] == REG_TYPE) {
        *term = arena->execs[i]->registry[loaded_op.args[j] - 1];
    } else if (loaded_op.args_type[j] == IND_TYPE) {
        get_indirect_value(arena, address, IND_SIZE, term);
    } else {
        *term = loaded_op.args[j];
    }
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#include "corewar/execution/execution.h"

void reset_dummy(loaded_op_t *dummy)
{
    dummy->is_op_loaded = 0;
    dummy->opcode = 0;
    for (int i = 0; i < 4; i++) {
        dummy->args_type[i] = 0;
        dummy->args_size[i] = 0;
        dummy->args[i] = 0;
    }
    dummy->pc_offset = 0;
    dummy->wait_cycle = 0;
}

int execution(arena_t *arena)
{
    loaded_op_t *dummy;

    while (1)
    {

    for (int i = 0; arena->execs[i]; i++) {
        dummy = &arena->execs[i]->loaded_op;
        if (dummy->is_op_loaded && !dummy->wait_cycle) {
            instructions[dummy->opcode - 1](arena, i);
            arena->execs[i]->pc += dummy->pc_offset;
            reset_dummy(dummy);
        }
        else if (!dummy->is_op_loaded) {
            read_op(arena, i, dummy);
            dummy->is_op_loaded = 1;
        }
        else {
            dummy->wait_cycle--;
        }
    }

    }
    return 0;
}

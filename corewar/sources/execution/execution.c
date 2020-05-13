/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#include "corewar/execution/execution.h"

void reset_loaded_op(loaded_op_t *loaded_op)
{
    loaded_op->is_op_loaded = 0;
    loaded_op->opcode = 0;
    for (int i = 0; i < 4; i++) {
        loaded_op->args_type[i] = NONE;
        loaded_op->args_size[i] = 0;
        loaded_op->args[i] = 0;
    }
    loaded_op->pc_offset = 0;
    loaded_op->wait_cycle = 0;
}

int execution(arena_t *arena)
{
    loaded_op_t *loaded_op;

    while (1)
    {

    for (int i = 0; arena->execs[i]; i++) {
        loaded_op = &arena->execs[i]->loaded_op;
        if (loaded_op->is_op_loaded && !loaded_op->wait_cycle) {
            instructions[loaded_op->opcode - 1](arena, i);
            arena->execs[i]->pc += loaded_op->pc_offset;
            reset_loaded_op(loaded_op);
        } else if (!loaded_op->is_op_loaded) {
            reset_loaded_op(loaded_op);
            if (read_op(arena, i, loaded_op)) {
                arena->execs[i]->pc++;
            } else {
                loaded_op->is_op_loaded = 1;
            }
        } else {
            loaded_op->wait_cycle--;
        }
        arena->execs[i]->pc %= MEM_SIZE;
    }
    arena->current_cycle++;
    //todo : verifier prog vivant, reset prog to dead,
    }
    return 0;
}

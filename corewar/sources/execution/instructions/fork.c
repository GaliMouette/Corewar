/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fork_instruction
*/

#include "corewar/execution/instructions/instructions.h"


int fork_instruction(arena_t *arena, int i)
{
    int offset = arena->execs[i]->loaded_op.args[0] % IDX_MOD;
    int pc = (arena->execs[i]->pc + offset) % MEM_SIZE;
    int nb_exec;

    for (nb_exec = 0; arena->execs[nb_exec]; nb_exec++);
    arena->execs = realloc(arena->execs, sizeof(*arena->execs) * (nb_exec + 2));
    if (!arena->execs) {
        return 1;
    }
    arena->execs[nb_exec + 1] = NULL;
    arena->execs[nb_exec] = malloc(sizeof(*arena->execs[i]));
    if (!arena->execs[nb_exec]) {
        return 1;
    }
    my_memcpy(arena->execs[nb_exec], arena->execs[i], sizeof(*arena->execs[i]));
    arena->execs[nb_exec]->loaded_op.is_op_loaded = 0;
    arena->execs[nb_exec]->pc = pc;
    return 0;
}

// void dup_program(arena_t *arena, int i, int nb_exec)
// {
    // arena->execs[nb_exec]->carry = arena->execs[i]->carry;
    // my_memcpy(arena->execs[nb_exec]->registry, arena->execs[i]->registry, 16);
    // arena->execs[nb_exec]->registry[0] = arena->nb_exec;
    // arena->execs[nb_exec]->loaded_op.is_op_loaded =
    // arena->execs[i]->loaded_op.is_op_loaded;
    // arena->execs[nb_exec]->loaded_op.opcode =
    // arena->execs[i]->loaded_op.opcode;
    // my_memcpy(arena->execs[nb_exec]->loaded_op.args_type,
    // arena->execs[i]->loaded_op.args_type, 4);
    // my_memcpy(arena->execs[nb_exec]->loaded_op.args_size,
    // arena->execs[i]->loaded_op.args_size, 4);
    // my_memcpy(arena->execs[nb_exec]->loaded_op.args,
    // arena->execs[i]->loaded_op.args, 4);
    // arena->execs[nb_exec]->loaded_op.pc_offset =
    // arena->execs[i]->loaded_op.pc_offset;
    // arena->execs[nb_exec]->loaded_op.wait_cycle =
    // arena->execs[i]->loaded_op.wait_cycle;
// }

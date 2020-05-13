/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** lfork_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int lfork_instruction(arena_t *arena, int i)
{
    int offset = arena->execs[i]->loaded_op.args[0];
    int pc = (arena->execs[i]->pc + offset) % MEM_SIZE;
    size_t nb_exec;

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

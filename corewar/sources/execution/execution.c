/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#include "corewar/execution/execution.h"

int execution(arena_t *arena)
{
    loaded_op_t *dummy;

    for (int i = 0; arena->execs[i]; i++) {
        dummy = &arena->execs[i]->loaded_op;
        if (dummy->is_op_loaded && !dummy->wait_cycle) {
            // Si pas operation cycle alors executer operation puis read suivante
            dummy->is_op_loaded = 0;
        }
        if (!dummy->is_op_loaded) {
            read_op(arena, i, dummy);
            dummy->is_op_loaded = 1;
        }
            // Sinon décrémenter cycle
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fork_instruction
*/

#include "corewar/execution/instructions/instructions.h"
#include <stdlib.h>

void dup_program(arena_t *arena, int i, int nb_player);

int fork_instruction(arena_t *arena, int i)
{
    int direct = arena->execs[i]->loaded_op.args[0];
    int nb_execs = 0;

    while (arena->execs[nb_execs]) {
        nb_execs++;
    }
    arena->execs = realloc(arena->execs, sizeof(arena->execs) + 1); //TODO null
    if (!arena->execs) {
        return 1;
    }
    arena->nb_players += 1;
    arena->execs[arena->nb_players] = NULL;
    arena->execs[arena->nb_players - 1] = malloc(sizeof(*arena->execs[i]));
    if (!arena->execs[arena->nb_players - 1]) {
        return 1;
    }
    arena->execs[arena->nb_players - 1]->pc = arena->execs[i]->pc + direct
    % IDX_MOD;
    dup_program(arena, i, arena->nb_players - 1);
    return 0;
}

//TODO nb_execs

void dup_program(arena_t *arena, int i, int nb_player)
{
    // my_memcpy(arena->execs[i], arena->execs[nb_player], sizeof(*arena->execs[i]));

    arena->execs[nb_player]->carry = arena->execs[i]->carry;
    my_memcpy(arena->execs[nb_player]->registry, arena->execs[i]->registry, 16);
    arena->execs[nb_player]->registry[0] = arena->nb_players;
    arena->execs[nb_player]->loaded_op.is_op_loaded =
    arena->execs[i]->loaded_op.is_op_loaded;
    arena->execs[nb_player]->loaded_op.opcode =
    arena->execs[i]->loaded_op.opcode;
    my_memcpy(arena->execs[nb_player]->loaded_op.args_type,
    arena->execs[i]->loaded_op.args_type, 4);
    my_memcpy(arena->execs[nb_player]->loaded_op.args_size,
    arena->execs[i]->loaded_op.args_size, 4);
    my_memcpy(arena->execs[nb_player]->loaded_op.args,
    arena->execs[i]->loaded_op.args, 4);
    arena->execs[nb_player]->loaded_op.pc_offset =
    arena->execs[i]->loaded_op.pc_offset;
    arena->execs[nb_player]->loaded_op.wait_cycle =
    arena->execs[i]->loaded_op.wait_cycle;
}

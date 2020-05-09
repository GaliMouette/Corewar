/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_arena
*/

#include "corewar/init/init_arena.h"

int init_arena(init_t *init, arena_t *arena)
{
    if (malloc_execs(init, arena)) {
        return 1;
    }
    for (int i = 0; i < count_players(init); i++) {
        if (load_exec_in_memory(init, arena, i)) {
            return 1;
        }
        init_exec(init, arena, i);
        init_player(init, arena, i);
    }
    return 0;
}

static int malloc_execs(init_t *init, arena_t *arena)
{
    arena->execs =
    malloc(sizeof(*arena->execs) * (size_t) (count_players(init) + 1));
    if (!arena->execs) {
        return 1;
    }
    arena->execs[count_players(init)] = NULL;
    return 0;
}

static void init_exec(init_t *init, arena_t *arena, int i)
{
    init_registers(init, arena, i);
    arena->execs[i]->pc = init->champs[i].load_address;
    arena->execs[i]->carry = 0;
}

static void init_registers(init_t *init, arena_t *arena, int i)
{
    arena->execs[i]->registry[0] = init->champs[i].number;
    for (int j = 1; j < REG_NUMBER - 1; j++) {
        arena->execs[i]->registry[j] = 0;
    }
}

static void init_player(init_t *init, arena_t *arena, int i)
{
    arena->players[i].name = init->champs[i].header.prog_name;
    arena->players[i].number = init->champs[i].number;
    arena->players[i].status = DEAD;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** initiate_arena
*/

#include "corewar/init/initiate_arena.h"

int initiate_arena(init_t *init, arena_t *arena)
{
    arena->nb_players = count_players(init);
    assign_addresses(init, arena);
    check_prog_overlap(init, arena);
    if (malloc_execs(arena)) {
        return 1;
    }
    for (int i = 0; i < arena->nb_players; i++) {
        if (load_exec_in_memory(init, arena, i)) {
            return 1;
        }
        init_exec(init, arena, i);
        init_player(init, arena, i);
    }
    return 0;
}

static int malloc_execs(arena_t *arena)
{
    arena->execs =
    malloc(sizeof(*arena->execs) * (size_t) (arena->nb_players + 1));
    if (!arena->execs) {
        return 1;
    }
    for (int i = 0; i < arena->nb_players; i++) {
        arena->execs[i] = malloc(sizeof(*arena->execs[i]));
        if (!arena->execs[i]) {
            return 1;
        }
    }
    arena->execs[arena->nb_players] = NULL;
    return 0;
}

static void init_exec(init_t *init, arena_t *arena, int i)
{
    arena->execs[i]->player = i + 1;
    arena->execs[i]->registry[0] = init->champs[i].number;
    for (int j = 1; j < REG_NUMBER - 1; j++) {
        arena->execs[i]->registry[j] = 0;
    }
    arena->execs[i]->pc = init->champs[i].load_address;
    arena->execs[i]->carry = 0;
    arena->execs[i]->loaded_op = (loaded_op_t) {0};
}

static void init_player(init_t *init, arena_t *arena, int i)
{
    arena->players[i].name = init->champs[i].header.prog_name;
    arena->players[i].number = init->champs[i].number;
    arena->players[i].status = DEAD;
}

int load_exec_in_memory(init_t *init, arena_t *arena, int i)
{
    int file_desc = init->champs[i].file_desc;
    char *memory = arena->memory;
    size_t address = (size_t) init->champs[i].load_address;
    size_t prog_size = (size_t) init->champs[i].header.prog_size;

    if (address > (address + prog_size) % MEM_SIZE) {
        read(file_desc, memory + address, MEM_SIZE - address);
        read(file_desc, memory, prog_size - (MEM_SIZE - address));
    } else {
        read(file_desc, memory + address, prog_size);
    }
    return 0;
}

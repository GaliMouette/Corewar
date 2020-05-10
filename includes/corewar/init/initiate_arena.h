/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** initiate_arena
*/

#ifndef INITIATE_ARENA_H_
#define INITIATE_ARENA_H_

#include "typedefs/arena_t.h"
#include "typedefs/init_t.h"
#include <stdlib.h>
#include <unistd.h>

int initiate_arena(init_t *init, arena_t *arena);
static int malloc_execs(arena_t *arena);
static void init_exec(init_t *init, arena_t *arena, int i);
static void init_player(init_t *init, arena_t *arena, int i);

//  Using
void assign_addresses(init_t *init, int nb_players);
int load_exec_in_memory(init_t *init, arena_t *arena, int i);
int count_players(init_t *init);

#endif /* !INITIATE_ARENA_H_ */

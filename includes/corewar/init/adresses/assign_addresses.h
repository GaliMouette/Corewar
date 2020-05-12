/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** assign_addresses
*/

#ifndef ASSIGN_ADDRESSES_H_
#define ASSIGN_ADDRESSES_H_

#include "typedefs/arena_t.h"
#include "typedefs/init_t.h"

void assign_addresses(init_t *init, arena_t *arena);
static void get_set_addresses_nb
(init_t *init, int nb_players, int *already_set);
static void simple_assign(init_t *init, int nb_players);

//  Using
void complex_assign(init_t *init, arena_t *arena, int already_set);

#endif /* !ASSIGN_ADDRESSES_H_ */

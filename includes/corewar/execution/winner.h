/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** winner
*/

#ifndef WINNER_H_
#define WINNER_H_

#include "typedefs/arena_t.h"
#include "utils.h"
#include <unistd.h>

void check_winner(arena_t *arena, int *winner, int set_last_alive);
void display_winner(arena_t *arena, int winner);

#endif /* !WINNER_H_ */

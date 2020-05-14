/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** winner
*/

#include "corewar/execution/winner.h"

void check_winner(arena_t *arena, int *winner)
{
    int players_alive = 0;

    for (int i = 0; i < 4; i++) {
        if (arena->players[i].status == ALIVE) {
            players_alive++;
            *winner = arena->players[i].number;
        }
    }
    if (1 != players_alive) {
        *winner = 0;
    }
}

void display_winner(arena_t *arena, int winner)
{
    int index = winner - 1;
    char *name  = arena->players[index].name;
    int number = arena->players[index].number;

    write(1, "The player ", 11);
    my_put_nbr(number);
    write (1, " (", 2);
    write(1, name, (size_t) my_strlen(name));
    write(1, ") has won.\n", 11);
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** count_players
*/

#include "corewar/init/count_players.h"

int count_players(init_t *init)
{
    int nb_players = 0;

    for (int i = 0; i < 4; i++) {
        if (init->champs[nb_players].path) {
            nb_players++;
        }
    }
    return nb_players;
}

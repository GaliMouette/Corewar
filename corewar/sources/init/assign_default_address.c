/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** assign_default_address
*/

#include "corewar/init/assign_default_address.h"

void assign_default_address(init_t *init, int nb_players)
{
    int nb_known = 0;

    init_useful_var(init, nb_players, &nb_known);
    if (nb_known == nb_players) {
        return;
    }
    if (nb_known < 2) {
        assign_little_known(init, nb_players);
    } else {
        assign_many_known(init, nb_players, nb_known);
    }
}

static void init_useful_var(init_t *init, int nb_players, int *nb_known)
{
    for (int i = 0; i != nb_players; i++) {
        if (-1 != init->champs[i].load_address) {
            (*nb_known)++;
            init->champs[i].load_address %= MEM_SIZE;
        }
    }
}

static void assign_little_known(init_t *init, int nb_players)
{
    int x = 0;

    for (int i = 0; i != nb_players; i++) {
        if (-1 != init->champs[i].load_address) {
            x = init->champs[i].load_address;
        }
    }
    for (int i = 0, j = 0; i != nb_players; i++) {
        if (-1 == init->champs[i].load_address) {
            j++;
            init->champs[i].load_address = j * (MEM_SIZE / nb_players) + x;
            init->champs[i].load_address %= MEM_SIZE;
        }
    }
}

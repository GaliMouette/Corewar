/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** assign_addresses
*/

#include "corewar/init/adresses/assign_addresses.h"

void assign_addresses(init_t *init, arena_t *arena)
{
    int already_set = 0;

    get_set_addresses_nb(init, arena->nb_players, &already_set);
    if (already_set == arena->nb_players) {
        return;
    }
    if (already_set < 2) {
        simple_assign(init, arena->nb_players);
    } else {
        complex_assign(init, arena, already_set);
    }
}

static void get_set_addresses_nb(init_t *init, int nb_players, int *already_set)
{
    for (int i = 0; i != nb_players; i++) {
        if (-1 != init->champs[i].load_address) {
            init->champs[i].load_address %= MEM_SIZE;
            (*already_set)++;
        }
    }
}

static void simple_assign(init_t *init, int nb_players)
{
    int x = 0;

    for (int i = 0; i < 4; i++) {
        if (-1 != init->champs[i].load_address) {
            x = init->champs[i].load_address;
        }
    }
    for (int i = 0, j = 0; i < 4; i++) {
        if (-1 == init->champs[i].load_address && init->champs[i].path) {
            j++;
            init->champs[i].load_address = j * (MEM_SIZE / nb_players) + x;
            init->champs[i].load_address %= MEM_SIZE;
        }
    }
}

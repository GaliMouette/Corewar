/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_address_overlap
*/

#include "corewar/init/check_address_overlap.h"

int check_address_overlap(init_t *init)
{
    int address[4] = {-1, -1, -1, -1};

    for (int i = 0, j = 0; i != count_players(init); i++) {
        if (-1 != init->champs[i].load_address) {
            address[j] = init->champs[i].load_address;
            j++;
        }
    }
    for (int i = 0; i != 3; i++) {
        if (-1 != address[i] && address[i] == address[i + 1]) {
            return 1;
        }
    }

    return 0;
}

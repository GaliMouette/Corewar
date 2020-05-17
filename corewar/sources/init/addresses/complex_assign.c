/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** complex_assing
*/

#include "corewar/init/adresses/complex_assign.h"

void complex_assign(init_t *init, arena_t *arena, int already_set)
{
    int addresses[3] = {-1, -1, -1};
    int nb_players = arena->nb_players;
    int third_address_is_set = 0;

    get_addresses(init, addresses);
    set_third_address(addresses);
    for (int i = 0; i != nb_players; i++) {
        if (2 == already_set && -1 == init->champs[i].load_address
        && !third_address_is_set && init->champs[i].path) {
            init->champs[i].load_address = addresses[2];
            third_address_is_set = 1;
        }
        if (-1 == init->champs[i].load_address && 4 == nb_players
        && init->champs[i].path) {
            SORT(addresses[0], addresses[1], addresses[2])
            set_fourth_address(init, i, addresses);
            init->champs[i].load_address %= MEM_SIZE;
        }
    }
}

static void get_addresses(init_t *init, int addresses[3])
{
    int index = 0;

    for (int i = 0; i < 4; i++) {
        if (-1 != init->champs[i].load_address) {
            addresses[index] = init->champs[i].load_address;
            index++;
        }
    }
}

static void set_third_address(int address[3])
{
    if (-1 == address[2]) {
        if ((address[1] - address[0]) > (MEM_SIZE - address[1] + address[0])) {
            address[2] = address[0] + ((address[1] - address[0]) / 2);
        } else {
            address[2] =
            address[1] + ((MEM_SIZE - address[1] + address[0]) / 2);
        }
        address[2] %= MEM_SIZE;
    }
}

static void set_fourth_address(init_t *init, int i, int address[3])
{
    int choice;

    if (address[0] > address[1]) {
        choice = address[0];
    } else if (address[1] > address[2]) {
        choice = address[1];
    } else {
        choice = address[2];
    }
    if ((CHOICE(choice, address[0]) - address[0] + address[1])
    > (CHOICE(choice, address[1]) - address[1] + address[2])) {
        init->champs[i].load_address = address[0]
        + ((CHOICE(choice, address[0]) - address[0] + address[1]) / 2);
    } else if ((CHOICE(choice, address[1]) - address[1] + address[2])
    > (CHOICE(choice, address[2]) - address[2] + address[0])) {
        init->champs[i].load_address = address[1]
        + ((CHOICE(choice, address[1]) - address[1] + address[2]) / 2);
    } else {
        init->champs[i].load_address = address[2]
        + ((CHOICE(choice, address[2]) - address[2] + address[0]) / 2);
    }
}

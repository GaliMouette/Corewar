/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** assign_many_known
*/

#include "corewar/init/assign_many_known.h"

void assign_many_known(init_t *init, int nb_players, int nb_known)
{
    int address[3] = {-1, -1, -1};
    int third_address_status = 0;

    get_load_address(init, nb_players, address);
    set_third_unknown(address);
    for (int i = 0; i != nb_players; i++) {
        if (2 == nb_known && -1 == init->champs[i].load_address
        && 0 == third_address_status) {
            init->champs[i].load_address = address[2];
            third_address_status++;
        }
        if (-1 == init->champs[i].load_address && 4 == nb_players) {
            SORT(address[0], address[1], address[2])
            set_fourth_unknown(init, i, address);
            init->champs[i].load_address %= MEM_SIZE;
        }
    }
}

static void get_load_address(init_t *init, int nb_players, int address[3])
{
    for (int i = 0; i != nb_players; i++) {
        if (-1 != init->champs[i].load_address && -1 == address[0]) {
            address[0] = init->champs[i].load_address;
            continue;
        }
        if (-1 != init->champs[i].load_address && -1 != address[0]
        && -1 == address[1]) {
            address[1] = init->champs[i].load_address;
            continue;
        }
        if (-1 != init->champs[i].load_address && -1 != address[0]
        && -1 != address[1]) {
            address[2] = init->champs[i].load_address;
            continue;
        }
    }
}

static void set_third_unknown(int address[3])
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

static void set_fourth_unknown(init_t *init, int i, int address[3])
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

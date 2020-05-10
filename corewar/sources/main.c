/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#include "corewar/main.h"

int main(int argc, char const *argv[])
{
    arena_t arena = ARENA;
    init_t init = INIT;

    if (1 == argc || 2 == argc) {
        write(1, USAGE, 580);
        return 0;
    }
    if (initiate(argv, &init)) {
        return 84;
    }
    initiate_arena(&init, &arena);
    for (int i = 0; i < 4; i++)
        printf("Player %d address %d\n", i, init.champs[i].load_address);
    return 0;
}

int assign_load_address(init_t *init);

static int initiate(char const *argv[], init_t *init)
{
    if (parse_args(argv, init)) {
        return 1;
    }
    if (check_files(init)) {
        return 1;
    }
    if (open_files(init)) {
        return 1;
    }
    return 0;
}

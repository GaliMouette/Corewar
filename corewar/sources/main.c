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

    if (1 == argc || (2 == argc && !my_strcmp(argv[1], "-h"))) {
        write(1, USAGE, 580);
        return 0;
    }
    if (initiate(argv, &init, &arena)) {
        return 84;
    }
    if (execution(&arena)) {
        return 84;
    }
    return 0;
}

int initiate(char const *argv[], init_t *init, arena_t *arena)
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
    if (initiate_arena(init, arena)){
        return 1;
    }
    return 0;
}

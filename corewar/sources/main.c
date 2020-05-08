/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#include "corewar/main.h"

int main(int argc, char const *argv[])
{
    __attribute__((unused)) arena_t arena = ARENA;
    init_t init = INIT;

    if (1 == argc || (2 == argc && !my_strcmp(argv[1], "-h"))) {
        write(1, USAGE, 580);
        return 0;
    }
    if (parse_args(argv, &init)) {
        return 84;
    }
    if (check_files(&init)) {
        return 84;
    }
    if (open_champs(&init)) {
        return 84;
    }
    return 0;
}

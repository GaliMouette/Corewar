/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#include "corewar/main.h"

int main(int argc, char const *argv[])
{
    init_t init = {-1, {{-1, -1, 0, {0}}, {-1, -1, 0, {0}}, {-1, -1, 0, {0}}, {-1, -1, 0, {0}}}};

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
    if (set_champion_from_file(&init)) {
        return 84;
    }
    return 0;
}

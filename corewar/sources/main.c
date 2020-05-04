/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#include "corewar/main.h"

int main(int argc, char const *argv[])
{
    int dump = -1;

    if (1 == argc || 2 == argc && !my_strcmp(argv[1], "-h")) {
        write(1, USAGE, 584);
        return 0;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#include "asm/main.h"

int main(int argc, char const *argv[])
{
    if (2 == argc && !my_strcmp("-h", argv[1])) {
        write(1, USAGE, 148);
        return 0;
    }
    if (2 < argc) {
        write(2, "Too many arguments.\n", 20);
        return 84;
    }
    if (1 == argc) {
        write(2, "Not enough arguments.\n", 22);
        return 84;
    }
    if (compile_file(argv[1])) {
        return 84;
    }
    return 0;
}

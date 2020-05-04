/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** set_dump
*/

#include "corewar/options/set_dump.h"

int set_dump(char *arg, init_t *init)
{
    if (check_error(arg, init)) {
        return 1;
    }
    init->dump = my_strtol(arg, 16);
    return 0;
}

static int check_error(char *arg, init_t *init)
{
    if (!arg) {
        write(2, "Missing dump argument.\n", 23);
        return 1;
    }
    for (int i = 0; arg[i]; i++) {
        if (!(0   <= arg[i] && arg[i] <= 9)
        ||  !('A' <= arg[i] && arg[i] <= 'F')
        ||  !('a' <= arg[i] && arg[i] <= 'f')) {
            write(2, "Dump argument is not hexadecimal.\n", 34);
            return 1;
        }
    }
    if (-1 != init->dump){
        write(2, "Double definition of dump.\n", 27);
        return 1;
    }
    return 0;
}

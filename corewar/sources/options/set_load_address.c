/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_load_address
*/

#include "corewar/options/set_load_address.h"

int set_load_address(char const *arg, int *i, init_t *init, int index)
{
    if (check_error(arg, init, index)) {
        return 1;
    }
    init->champs[index].load_address = (int) my_strtol(arg, 16);
    *i += 1;
    return 0;
}

static int check_error(char const *arg, init_t *init, int index)
{
    if (-1 != init->champs[index].load_address) {
        write(2, "Multiple definition -a option.\n", 31);
        return 1;
    }
    if (!arg) {
        write(2, "Missing argument for -a option.\n", 32);
        return 1;
    }
    if (arg[0] == '-') {
        write(2, "Argument of -a option cannot be negative.\n", 42);
        return 1;
    }
    if (is_hex(arg)) {
        write(2, "Argument of -a option is not hexadecimal.\n", 42);
        return 1;
    }
    return 0;
}

static int is_hex(char const *arg)
{
    for (int i = 0; arg[i]; i++) {
        if (!('0' <= arg[i] && arg[i] <= '9')
        &&  !('A' <= arg[i] && arg[i] <= 'F')
        &&  !('a' <= arg[i] && arg[i] <= 'f')) {
            return 1;
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** get_name
*/

#include "asm/header/get_name.h"

int get_name(char *args, header_t *header, int is_set)
{
    static int set = 0;

    if (is_set) {
        return set;
    }
    if (check_errors(args, set)) {
        return 1;
    }
    my_memcpy(header->prog_name, args + 1, my_strlen(args + 1) - 1);
    set = 1;
    return 0;
}

static int check_errors(char *args, int set)
{
    if (set) {
        write(2, "The name can only be defined once.\n", 35);
        return 1;
    }
    if (my_strlen(args) > MAX_PROG_NAME_LEN + 2) {
        write(2, "Program name is too long.\n", 26);
        return 1;
    }
    return 0;
}

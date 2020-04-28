/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** get_comment
*/

#include "header.h"
#include "utils.h"
#include <unistd.h>

static int check_errors(char *args, int set);

int get_comment(char *args, header_t *header, int is_set)
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
        write(2, "The comment can only be defined once.\n", 35);
        return 1;
    }
    if (my_strlen(args) > MAX_COMMENT_LEN + 2) {
        write(2, "Program name is too long.\n", 26);
        return 1;
    }
    if (!get_name(NULL, NULL, 1)) {
        write(2, "The comment must be just after the name.\n", 41);
        return 1;
    }
    return 0;
}

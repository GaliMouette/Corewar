/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** get_header
*/

#include "asm.h"
#include "op.h"
#include "utils.h"
#include <unistd.h>

static int check_errors(char *args);

int get_header(char *line, header_t *header, int is_set)
{
    static int set = 0;
    char *args = my_strtok(NULL, "");

    if (is_set) {
        return set;
    }
    if (check_errors(args)) {
        return 1;
    }
    if (!my_strcmp(line, ".name")) {
        // Get name
    } else if (!my_strcmp(line, ".comment")) {
        // Get comment
    }
    return 0;
}

static int check_errors(char *args)
{
    if ('\"' != args[0]
    || !my_strstr(args + 1, "\"")
    || my_strstr(args + 1, "\"")[1]) {
        write(2, "Syntax error.\n", 14);
        return 1;
    }
    return 0;
}

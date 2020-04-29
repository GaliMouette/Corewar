/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** get_header
*/

#include "asm/header/get_header.h"

int get_header(char *line, header_t *header, int is_set)
{
    char *args = my_strtok(NULL, "");

    if (is_set) {
        return get_name(NULL, NULL, 1) && get_comment(NULL, NULL, 1);
    }
    if (check_errors(args)) {
        return 1;
    }
    if (!my_strcmp(line, NAME_CMD_STR)) {
        if (get_name(args, header, 0)) {
            return 1;
        }
    } else if (!my_strcmp(line, COMMENT_CMD_STR)) {
        if (get_comment(args, header, 0)){
            return 1;
        }
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

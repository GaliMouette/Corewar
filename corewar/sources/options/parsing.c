/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** parsing
*/

#include "corewar/options/parsing.h"

int parse_args(char *argv[], init_t *init)
{
    int i = 1;
    int index = 0;

    while (argv[i]) {
        if (!my_strcmp(argv[i], "-dump")) {
            if (set_dump(argv[i + 1], init)) {
                return 1;
            }
            i += 2;
            continue;
        }
        if (set_prog_args(argv, &i, init, &index)) {
            return 1;
        }
        i++;
    }
    return 0;
}

static int set_prog_args(char *argv[], int *i, init_t *init, int *index)
{
    if (!my_strcmp(argv[*i], "-n")) {
        if (set_prog_nbr(argv[*i + 1], i, init, *index)) {
            return 1;
        }
    } else if (!my_strcmp(argv[*i], "-a")) {
        if (set_load_address(argv[*i + 1], i, init, *index)) {
            return 1;
        }
    } else {
        init->champs[*index].path = argv[*i];
        (*index)++;
    }
    if (*index > 4) {
        write(2, "The number of champion load is above the limit.\n", 48);
        return 1;
    }
    return 0;
}

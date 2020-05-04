/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** parsing
*/

#include "corewar/options/parsing.h"

int parse_args(char const *argv[], init_t *init)
{
    int i = 1;

    while (argv[i]) {
        if (!my_strcmp(argv[i], "-dump")) {
            if (set_dump(argv[i], init)) {
                return 1;
            }
        }
        i++;
    }
}

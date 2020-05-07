/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_prog_nbr
*/

#include "corewar/options/set_prog_nbr.h"

int set_prog_nbr(char const *arg, int *i, init_t *init, int index)
{
    if (check_error(arg, init, index)) {
        return 1;
    }
    init->champs[index].number = my_atoi(arg);
    *i += 1;
    return 0;
}

static ssize_t check_error(char const *arg, init_t *init, int index)
{
    ssize_t status = 0;

    if (-1 != init->champs[index].number) {
        status = write(2, "Multiple definition -n option.\n", 31);
    }
    if (!status && !arg) {
        status = write(2, "Missing argument for -n option.\n", 32);
    }
    if (!status && !is_digit(arg)) {
        status = write(2, "Argument of -n option is not a number.\n", 39);
    }
    if (!status && (my_atoi(arg) <= 0 || my_atoi(arg) >= 5)) {
        status = write(2, "Player number must be between 1 and 4.\n", 39);
    }
    for (int i = 0; !status && i < 4; i++) {
        if (my_atoi(arg) == init->champs[i].number) {
            status = write(2, "Player number already attributed.\n", 34);
        }
    }
    return status;
}

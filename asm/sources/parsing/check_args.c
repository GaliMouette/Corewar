/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** check_args
*/

#include "asm/parsing/check_args.h"

int check_nb_args(char *args[6], int index)
{
    int nb_args = 0;

    while (args[nb_args]) {
        nb_args++;
    }
    if (nb_args - 1 > op_tab[index].nbr_args) {
        write(2, "Too many arguments for instruction.\n", 36);
    } else if (nb_args - 1 < op_tab[index].nbr_args) {
        write(2, "Not enough arguments for instruction.\n", 38);
    }
    return nb_args - 1 != op_tab[index].nbr_args;
}

int check_args_types(char *args[6], int index)
{
    int i = 1;
    int status = 0;

    while (args[i] && !status) {
        switch (args[i][0]){
        case 'r':
            status = check_registry(args[i], index, i - 1);
            break;
        case DIRECT_CHAR:
            status = check_direct(args[i], index, i - 1);
            break;
        default:
            status = check_indirect(args[i], index, i - 1);
            break;
        }
        i++;
    }
    return status;
}

static int check_registry(char *arg, int op_index, int arg_index)
{
    int registry = 0;

    if (!(T_REG & op_tab[op_index].type[arg_index])) {
        write(2, "Invalid argument type.\n", 23);
        return 1;
    }
    if (!is_digit(arg + 1)) {
        write(2, "Registry argument is not a number.\n", 35);
        return 1;
    }
    registry = my_atoi(arg + 1);
    if (registry < 1 || REG_NUMBER < registry) {
        write(2, "Invalid registry number.\n", 25);
        return 1;
    }
    return 0;
}

static int check_direct(char *arg, int op_index, int arg_index)
{
    if (!(T_DIR & op_tab[op_index].type[arg_index])) {
        write(2, "Invalid argument type.\n", 23);
        return 1;
    }
    if (LABEL_CHAR == arg[1]) {
        if (my_strlen(arg + 2) != my_strspn(arg + 2, LABEL_CHARS)) {
            write(2, "Reference to invalid label.\n", 28);
            return 1;
        } else {
            return 0;
        }
    }
    if (!is_digit(arg + 1)) {
        write(2, "Direct argument is not a number.\n", 33);
        return 1;
    }
    return 0;
}

static int check_indirect(char *arg, int op_index, int arg_index)
{
    if (!(T_IND & op_tab[op_index].type[arg_index])) {
        write(2, "Invalid argument type.\n", 23);
        return 1;
    }
    if (LABEL_CHAR == arg[0]) {
        if (my_strlen(arg + 1) != my_strspn(arg + 1, LABEL_CHARS)) {
            write(2, "Reference to invalid label.\n", 28);
            return 1;
        } else {
            return 0;
        }
    }
    if (!is_digit(arg)) {
        write(2, "Indirect argument is not a number.\n", 36);
        return 1;
    }
    return 0;
}

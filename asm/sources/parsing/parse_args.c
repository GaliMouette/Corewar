/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** parse_args
*/

#include "asm/parsing/parse_args.h"

int parse_args
(char *args[6], labels_t *saved_labels, int *label, instruction_t **head)
{
    int index = get_mnemonique_index(args[0]);

    if (*label && !args[0]) {
        *label = 1;
        return 0;
    }
    if (check_errors(args, index)) {
        return 1;
    }
    if (add_instruction(args, head, (int [2]) {index, *label}, saved_labels)) {
        return 1;
    }
    *label = 0;
    return 0;
}

static int get_mnemonique_index(char *arg)
{
    int index = -1;
    int i = 0;

    while (-1 == index && op_tab[i].mnemonique) {
        if (!my_strcmp(arg, op_tab[i].mnemonique)) {
            index = i;
        }
        i++;
    }
    return index;
}

static int check_errors(char *args[6], int index)
{
    if (!get_header(NULL, NULL, 1)) {
        write(2, "Missing or incomplete program header.\n", 38);
        return 1;
    }
    if (-1 == index) {
        write(2, "Invalid instruction.\n", 21);
        return 1;
    }
    if (check_nb_args(args, index)) {
        write(2, "Too many arguments for instruction.\n", 36);
        return 1;
    }
    if (check_args_types(args, index)) {
        return 1;
    }
    return 0;
}

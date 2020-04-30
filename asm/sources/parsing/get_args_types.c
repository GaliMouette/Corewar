/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** get_args_types
*/

#include "asm/parsing/get_args_types.h"

int get_args_types(char *args[6])
{
    int type = 0;
    int i = 1;

    while (args[i]) {
        switch (args[i][0]) {
        case 'r':
            type |= 1 << (8 - i * 2);
            break;
        case '%':
            type |= 2 << (8 - i * 2);
            break;
        default:
            type |= 3 << (8 - i * 2);
            break;
        }
        i++;
    }
    return type;
}

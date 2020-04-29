/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** get_args_types
*/

#include "asm/parsing/get_args_types.h"

_Pragma("clang diagnostic push")
_Pragma("clang diagnostic ignored \"-Wgnu-binary-literal\"")

int get_args_types(char *args[6])
{
    int type = 0;
    int i = 1;

    while (args[i]) {
        switch (args[i][0]) {
        case 'r':
            type |= 0b01 << (8 - i * 2);
            break;
        case '%':
            type |= 0b10 << (8 - i * 2);
            break;
        default:
            type |= 0b11 << (8 - i * 2);
            break;
        }
        i++;
    }
    return type;
}

_Pragma("clang diagnostic pop")

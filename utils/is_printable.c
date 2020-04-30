/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_printable
*/

#include "utils.h"

int is_printable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 32 || str[i] > 126)
            return 0;
    return 1;
}

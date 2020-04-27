/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_digit
*/

#include "utils.h"

int is_digit(char const *str)
{
    if (!str) {
        return 0;
    }
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_digit
*/

#include "utils.h"

int is_digit(char const *str)
{
    int i = 0;

    if (!str) {
        return 0;
    }
    if ('-' == str[i])
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

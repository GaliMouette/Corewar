/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strlen
*/

#include "utils.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}

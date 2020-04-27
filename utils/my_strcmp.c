/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcmp
*/

#include "utils.h"

int my_strcmp(char const *str1, char const *str2)
{
    while (*str1) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

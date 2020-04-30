/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** my_strnlen
*/

#include "utils.h"

int my_strnlen(char const *str, int n)
{
    int len;

    for (len = 0; len < n; len++, str++) {
        if (!*str) {
            break;
        }
    }
    return len;
}

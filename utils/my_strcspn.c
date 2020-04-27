/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcspn
*/

#include "utils.h"

int my_strcspn(char const *str, char const *chars)
{
    int i, j;

    for (i = 0; str[i]; i++) {
        for (j = 0; chars[j]; j++) {
            if (str[i] == chars[j]) {
                return i;
            }
        }
    }
    return i;
}

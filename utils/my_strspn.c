/*
** EPITECH PROJECT, 2020
** PSU_corewar_2019
** File description:
** my_strspn
*/

#include "utils.h"

int my_strspn(char const *str, char const *chars)
{
    int i, j;

    for (i = 0; str[i]; i++) {
        for (j = 0; chars[j]; j++) {
            if (str[i] == chars[j]) {
                j = -1;
                break;
            }
        }
        if (-1 != j) {
            break;
        }
    }
    return i;
}

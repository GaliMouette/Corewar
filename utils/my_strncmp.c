/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** my_strncmp
*/

#include "utils.h"

int my_strncmp(const char *str_1, const char *str_2, int n)
{
    unsigned char c1, c2;

    while (n-- > 0) {
        c1 = (unsigned char) *str_1++;
        c2 = (unsigned char) *str_2++;
        if (c1 != c2) {
            return c1 - c2;
        }
        if (c1 == '\0') {
            return 0;
        }
    }
    return 0;
}

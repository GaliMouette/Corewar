/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** my_strtol.c
*/

#include "utils.h"

long my_strtol(const char *str, int base)
{
	int c;
    long result = 0;

    while ((c = *str++)) {
        if (ISDIGIT(c)) {
            c -= '0';
        } else if (ISALPHA(c)) {
            c -= (ISUPPER(c)) ? 'A' - 10 : 'a' - 10;
        }
        result *= base;
        result += c;
    }
    return result;
}

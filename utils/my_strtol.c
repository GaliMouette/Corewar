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

/*
int my_puissance(int nb, int puissance)
{
    int result = 1;

    for (int i = 0; i != puissance; i++)
        result *= nb;
    return result;
}

long my_base_to_deci(char *str, int base)
{
    long result = 0;
    int rank = 0;

    for (int i = my_strlen(str) - 1; str[i]; i--, rank++) {
        if ('A' <= str[i] && str[i] <= 'F') {
            result += (str[i] - ('A' - 10)) * my_puissance(base, rank);
        } else if ('a' <= str[i] && str[i] <= 'f') {
            result += (str[i] - ('a' - 10)) * my_puissance(base, rank);
        } else {
            result += (str[i] - '0') * my_puissance(base, rank);
        }
    }
    return result;
}
*/

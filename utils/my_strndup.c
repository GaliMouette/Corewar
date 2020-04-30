/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** my_strndup
*/

#include "utils.h"
#include <stdlib.h>

char *my_strndup(const char *s, int n)
{
    int len = my_strnlen(s, n);
    char *new = (char *) malloc((unsigned long)  len + 1);

    if (!new)
        return new;
    new[len] = '\0';
    return (char *) my_memcpy(new, s, len);
}

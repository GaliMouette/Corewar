/*
** EPITECH PROJECT, 2020
** PSU_corewar_2019
** File description:
** my_strstr
*/

#include "utils.h"
#include <stddef.h>

char *my_strstr(char *haystack, char *needle)
{
    int i;

    while (*haystack) {
        i = 0;
        while (haystack[i] && needle[i] && haystack[i] == needle[i]) {
            i++;
        }
        if (!needle[i])
            return haystack;
        haystack++;
    }
    return NULL;
}

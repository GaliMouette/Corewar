/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** my_memcpy
*/

#include "utils.h"

void *my_memcpy(void *dest, const void *src, int n)
{
    char *char_dest = (char *) dest;
    const char *char_src = (const char *) src;

    if (char_dest && char_src) {
        while (n) {
            *(char_dest++) = *(char_src++);
            n--;
        }
    }
    return dest;
}

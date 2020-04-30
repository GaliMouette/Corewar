/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** my_memmove
*/

#include "utils.h"

void *my_memmove(void *dest, const void *src, int n)
{
    unsigned char cpy_byte = 1;
    char *char_dest = (char *) dest;
    const char *char_src = (const char *) src;

    if (char_dest == char_src) {
        cpy_byte = 0;
    } else {
        char_dest += n;
        char_src += n;
    }
    if (cpy_byte) {
        while (n) {
            *(--char_dest) = *(--char_src);
            n--;
        }
    }
    return dest;
}

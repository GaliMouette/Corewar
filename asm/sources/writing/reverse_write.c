/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** reverse_write
*/

#include "asm/writting/reverse_write.h"

void reverse_write(int fd, const void *buf, int n)
{
    int i = n - 1;
    const char *buffer = (const char *) buf;

    while (i >= 0) {
        write(fd, buffer + i, 1);
        i--;
    }
}

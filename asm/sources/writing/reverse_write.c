/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** reverse_write
*/

#include <unistd.h>

int reverse_write(int fd, const void *buf, int n);

int reverse_write(int fd, const void *buf, int n)
{
    int i = n - 1;
    const char *buffer = (const char *) buf;

    while (i >= 0) {
        if (write(fd, buffer + i, 1) == -1)
            return 1;
        i--;
    }
    return 0;
}

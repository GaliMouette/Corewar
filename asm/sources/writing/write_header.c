/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** display_header
*/

#include "typedefs/header_t.h"
#include <unistd.h>

int reverse_write(int fd, const void *buf, int n);
int write_header(header_t *header, int fd);

int write_header(header_t *header, int fd)
{
    if (reverse_write(fd, &header->magic, sizeof(header->magic)) == -1)
        return 1;
    if (write(fd, &header->prog_name, sizeof(header->prog_name)) == -1)
        return 1;
    if (reverse_write(fd, &header->prog_size, sizeof(header->prog_size)) == -1)
        return 1;
    if (write(fd, &header->comment, sizeof(header->comment)) == -1)
        return 1;
    if (write(fd, &header->padding, sizeof(header->padding)) == -1)
        return 1;
    return 0;
}

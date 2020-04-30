/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** display_header
*/

#include "asm/writting/write_header.h"

void write_header(header_t *header, int fd)
{
    reverse_write(fd, &header->magic, sizeof(header->magic));
    write(fd, header->prog_name, sizeof(header->prog_name));
    reverse_write(fd, &header->prog_size, sizeof(header->prog_size));
    write(fd, header->comment, sizeof(header->comment));
    write(fd, &header->padding, sizeof(header->padding));
}

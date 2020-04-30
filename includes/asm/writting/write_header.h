/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** write_header
*/

#ifndef WRITE_HEADER_H_
#define WRITE_HEADER_H_

#include "typedefs/header_t.h"
#include <unistd.h>

int write_header(header_t *header, int fd);

//  Using
int reverse_write(int fd, const void *buf, int n);

#endif /* !WRITE_HEADER_H_ */

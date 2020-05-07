/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** open_champs.h
*/

#ifndef OPEN_CHAMPS_H_
#define OPEN_CHAMPS_H_

#include "bswap.h"
#include "typedefs/init_t.h"
#include "typedefs/header_t.h"
#include <fcntl.h>
#include <unistd.h>

int open_champs(init_t *init);
static int open_file(char const *path, int *fd);
static int get_header(int fd, header_t *header);
static int check_magic(int fd, header_t *header);

#endif /* !OPEN_CHAMPS_H_ */

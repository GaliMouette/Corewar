/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_champion_from_file
*/

#ifndef SET_CHAMPION_FROM_FILE_H_
#define SET_CHAMPION_FROM_FILE_H_

#include "typedefs/init_t.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int set_champion_from_file(init_t *init);
static int open_file(char const *path);
static int read_file(int fd, char **buffer);
static int is_valid_magic_number(char *buffer);

#endif /* !SET_CHAMPION_FROM_FILE_H_ */

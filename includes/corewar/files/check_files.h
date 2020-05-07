/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_files
*/

#ifndef CHECK_FILES_H_
#define CHECK_FILES_H_

#include "typedefs/init_t.h"
#include "utils.h"
#include <unistd.h>

int check_files(init_t *init);
static int check_file_format(char *path);

#endif /* !CHECK_FILES_H_ */

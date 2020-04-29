/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#ifndef COMPILE_FILE_H_
#define COMPILE_FILE_H_

#include "header_t.h"
#include <stdio.h>
#include <unistd.h>

int compile_file(char const *path);
static FILE *open_file(char const *path);

#endif /* !COMPILE_FILE_H_ */

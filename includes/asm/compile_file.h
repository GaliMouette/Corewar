/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#ifndef COMPILE_FILE_H_
#define COMPILE_FILE_H_

#include "asm.h"
#include "header.h"
#include "labels_t.h"
#include "op.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static FILE *open_file(char const *path);
static int parse_file(FILE *file, header_t *header);
static int parse_line(char *line, header_t *header, labels_t *saved_labels);

#endif /* !COMPILE_FILE_H_ */

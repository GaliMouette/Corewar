/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#include "asm.h"
#include "op.h"
#include <stdio.h>
#include <unistd.h>

int parse_file(FILE *file, header_t *header)
{
    char *line = NULL;
    size_t n = 0;

    while (-1 != getline(&line, &n, file)) {
        if (clean_line(line)) {
            continue;
        }
        //  Get header -> and check
        //  Check label
        //  Add instruction -> and check
    }
    return 0;
}

int compile_file(char const *path)
{
    FILE *file = open_file(path);
    header_t header = {MAGIC, {0}, 0, {0}};

    if (!file) {
        return 1;
    }
    parse_file(file, &header);
    // Create and write file.cor
    fclose(file);
    return 0;
}

FILE *open_file(char const *path)
{
    FILE *file = fopen(path, "r");

    if (!file) {
        write(2, "No such file.\n", 14);
    }
    return file;
}

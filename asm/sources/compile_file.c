/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#include "asm/compile_file.h"

int compile_file(char const *path)
{
    FILE *file = open_file(path);
    header_t header = {MAGIC, {0}, 0, {0}, 0};

    if (!file) {
        return 1;
    }
    if (parse_file(file, &header)) {
        return 1;
    }
    // Create and write file.cor
    fclose(file);
    return 0;
}

static FILE *open_file(char const *path)
{
    FILE *file = fopen(path, "r");

    if (!file) {
        write(2, "No such file.\n", 14);
    }
    return file;
}

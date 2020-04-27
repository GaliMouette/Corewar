/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#include "asm.h"
#include <stdio.h>
#include <unistd.h>

int compile_file(char const *path)
{
    FILE *file = open_file(path);

    if (!file) {
        return 1;
    }
    // Parse file(.s)
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

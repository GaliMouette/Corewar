/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_files
*/

#include "corewar/files/check_files.h"

int check_files(init_t *init)
{
    for (int i = 0; i < 4; i++) {
        if ((init->champs[i].load_address != -1 || init->champs[i].number != -1)
        && !init->champs[i].path) {
            write(2, "Missing champion.\n", 18);
            return 1;
        }
        if (init->champs[i].path && check_file_format(init->champs[i].path)) {
            return 1;
        }
    }
    return 0;
}

static int check_file_format(char const *path)
{
    char *ptr = my_strstr(path, ".cor");

    while (ptr && my_strstr(ptr + 1, ".cor")) {
        ptr = my_strstr(ptr + 1, ".cor");
    }
    if (!ptr || ptr[4]) {
        write(2, "Wrong file format (.cor expected).\n", 35);
        return 1;
    } else {
        return 0;
    }
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** set_champion_from_file
*/

#include "corewar/files/set_champion_from_file.h"

int set_champion_from_file(init_t *init)
{
    int fd;
    char *buffer;

    for (int i = 0; init->champs[i].path; i++) {
        fd = open_file(init->champs[i].path);
        if (-1 == fd) {
            return 1;
        }
        if (read_file(fd, &buffer)) {
            return 1;
        }
        if (!is_valid_magic_number(buffer)) {
            return 1;
        }
        free(buffer);
    }
    return 0;
}

static int open_file(char const *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        write(2, "No such file.\n", 14);
        return -1;
    }
    return fd;
}

static int read_file(int fd, char **buffer)
{
    size_t size_file = (size_t) lseek(fd, 0, SEEK_END);

    if (!size_file) {
        write(2, "File is empty.\n", 15);
        close(fd);
        return 1;
    }
    lseek(fd, 0, SEEK_SET);
    *buffer = malloc(size_file + 1);
    read(fd, *buffer, size_file);
    return 0;
}

static int is_valid_magic_number(char *buffer)
{
    if (((unsigned int) buffer[0] != 0x0)
    || ((unsigned int) buffer[1] != 0xffffffea)
    || ((unsigned int) buffer[2] != 0xffffff83)
    || ((unsigned int) buffer[3] != 0xfffffff3)) {
        write(2, "Wrong file format (bad magic number).\n", 38);
        return 0;
    }
    return 1;
}

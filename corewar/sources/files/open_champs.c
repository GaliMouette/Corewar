/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_champs
*/

#include "corewar/files/open_champs.h"

int open_champs(init_t *init)
{
    for (int i = 0; init->champs[i].path; i++) {
        if (open_file(init->champs[i].path, &init->champs[i].file_desc)) {
            return 1;
        }
        if (get_header(init->champs[i].file_desc, &init->champs[i].header)) {
            return 1;
        }
    }
    return 0;
}

static int open_file(char const *path, int *fd)
{
    *fd = open(path, O_RDONLY);
    if (*fd == -1) {
        write(2, "No such file.\n", 14);
        return 1;
    } else {
        return 0;
    }
}

static int get_header(int fd, header_t *header)
{
    read(fd, &header->magic, 4);
    header->magic = (int) BSWAP_INT((unsigned int) header->magic);
    read(fd, header->prog_name, MAX_PROG_NAME_LEN);
    read(fd, &header->prog_size, 4);
    header->prog_size = (long) BSWAP_LONG((unsigned long) header->prog_size);
    read(fd, header->comment, MAX_COMMENT_LEN);
    if (check_magic(fd, header)) {
        return 1;
    } else {
        return 0;
    }
}

static int check_magic(int fd, header_t *header)
{
    if (header->magic != MAGIC) {
        write(2, "Wrong file format (bad magic number).\n", 38);
        return 1;
    } else {
        return 0;
    }
}

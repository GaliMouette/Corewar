/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_files
*/

#include "corewar/files/open_files.h"

int open_files(init_t *init)
{
    sort_champs(init);
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

static void sort_champs(init_t *init)
{
    init_t dummy = INIT;

    for (int i = 0; i < 4; i++) {
        if (-1 != init->champs[i].number) {
            dummy.champs[init->champs[i].number - 1] = init->champs[i];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; -1 == dummy.champs[i].number && j < 4; j++) {
            if (-1 == init->champs[j].number) {
                init->champs[j].number = i + 1;
                dummy.champs[i] = init->champs[j];
            }
        }
    }
    *init = dummy;
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
    read(fd, &header->prog_size, 8);
    header->prog_size = (long) BSWAP_LONG((unsigned long) header->prog_size);
    read(fd, header->comment, MAX_COMMENT_LEN);
    lseek(fd, 4, SEEK_CUR);
    if (check_magic(header)) {
        return 1;
    } else {
        return 0;
    }
}

static int check_magic(header_t *header)
{
    if (header->magic != MAGIC) {
        write(2, "Wrong file format (bad magic number).\n", 38);
        return 1;
    } else {
        return 0;
    }
}

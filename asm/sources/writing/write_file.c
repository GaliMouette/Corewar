/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** write_file
*/

#include "asm/writting/write_file.h"

int write_file(char const *path, header_t *header, instruction_t *head)
{
    int ouput = open_file(path);

    if (-1 == ouput) {
        return 1;
    }
    write_header(header, ouput);
    if (!head) {
        return 0;
    }
    write_instructions(head, ouput);
    return 0;
}

static int open_file(char const *path)
{
    char buffer[256] = {0};
    char *end;

    my_memcpy(buffer, path, my_strlen(path));
    end = my_strstr(buffer, ".s");
    while (end && end[2]) {
        end = my_strstr(end + 1, ".s");
    }
    if (!end) {
        end = buffer + my_strlen(path);
    }
    my_memcpy(end, ".cor", 5);
    return open(buffer, O_WRONLY | O_CREAT, 0666);
}

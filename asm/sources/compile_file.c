/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#include "asm/compile_file.h"
#include "utils.h"
#include <fcntl.h>

int compile_file(char const *path)
{
    FILE *file = open_file(path);
    int ouput = open_output(path);
    header_t header = {MAGIC, {0}, 0, {0}, 0};
    instruction_t *head = NULL;

    if (!file) {
        return 1;
    }
    if (parse_file(file, &header, &head)) {
        return 1;
    }
    header.prog_size = calculate_pc(head);
    replace_labels(head);
    write_header(&header, ouput);
    write_instructions(head, ouput);
    fclose(file);
    return 0;
}

static FILE *open_file(char const *path)
{
    FILE *file = fopen(path, "r+");

    if (!file) {
        write(2, "No such file.\n", 14);
    }
    return file;
}

int open_output(char *path)
{
    char buffer[256] = {0};
    char *end;

    my_memcpy(buffer, path, my_strlen(path));
    end = my_strstr(buffer, ".s");
    while (end && end[2]) {
        end = my_strstr(buffer + 1, ".s");
    }
    if (!end) {
        end = buffer + my_strlen(path);
    }
    my_memcpy(end, ".cor", 5);
    return open(buffer, O_WRONLY | O_CREAT, 0666);
}

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
    instruction_t *head = NULL;

    if (!file) {
        return 1;
    }
    if (parse_file(file, &header, &head)) {
        fclose(file);
        return 1;
    }
    header.prog_size = calculate_pc(head);
    if (replace_labels(head) || write_file(path, &header, head)) {
        free_instruction(head);
        fclose(file);
        return 1;
    }
    free_instruction(head);
    fclose(file);
    return 0;
}

static FILE *open_file(char const *path)
{
    FILE *file = fopen(path, "r");
    int input = -1;

    if (!file) {
        write(2, "No such file.\n", 14);
    }
    input = open(path, O_RDONLY);
    if (-1 == input) {
        if (file) {
            fclose(file);
        }
        return NULL;
    }
    if (!lseek(input, 0, SEEK_END)) {
        write(2, "File is empty.\n", 15);
        fclose(file);
        file = NULL;
    }
    close(input);
    return file;
}

static void free_instruction(instruction_t *head)
{
    instruction_t *dummy;

    while (head) {
        dummy = head->next;
        free(head->label);
        free(head->labels[0]);
        free(head->labels[1]);
        free(head->labels[2]);
        free(head);
        head = dummy;
    }
}

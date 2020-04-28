/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#include "asm.h"
#include "header.h"
#include "label.h"
#include "op.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static FILE *open_file(char const *path);

static int parse_file(FILE *file, header_t *header);

static int parse_line(char *line, header_t *header, labels_t *saved_labels);

int compile_file(char const *path)
{
    FILE *file = open_file(path);
    header_t header = {MAGIC, {0}, 0, {0}};

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

static int parse_file(FILE *file, header_t *header)
{
    char *line = NULL;
    size_t n = 0;
    static labels_t saved_labels = {0};

    while (-1 != getline(&line, &n, file)) {
        if (clean_line(line)) {
            continue;
        }
        if (parse_line(line, header, &saved_labels)) {
            freearray((void **) saved_labels.labels);
            free(line);
            return 1;
        }
    }
    freearray((void **) saved_labels.labels);
    free(line);
    return 0;
}

static int parse_line(char *line, header_t *header, labels_t *saved_labels)
{
    line = my_strtok(line, " ");
    if (!my_strcmp(line, ".name") || !my_strcmp(line, ".comment")) {
        if (get_header(line, header, 0)) {
            return 1;
        }
    }
    if (my_strstr(line, LABEL_STR)) {
        if (check_label(line, saved_labels)) {
            return 1;
        }
    }
    //  Check mnemonique or opcode
    return 0;
}

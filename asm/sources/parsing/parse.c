/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** parse
*/

#include "asm/label.h"
#include "asm/header/get_header.h"
#include "typedefs/labels_t.h"
#include "typedefs/header_t.h"
#include <stdio.h>
#include <stdlib.h>
#include "op.h"

int parse_file(FILE *file, header_t *header)
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

void fill_args(char *args[6], char *line, int label)
{
    int i = 1;

    if (2 == label) {
        args[0] = my_strtok(NULL, " ");
    } else {
        args[0] = line;
    }
    while (i < 6) {
        args[i] = my_strtok(NULL, " ");
        i++;
    }
}

int parse_line(char *line, header_t *header, labels_t *saved_labels)
{
    static int label = 0;
    char *args[6] = {0};

    line = my_strtok(line, " ");
    if (!my_strcmp(line, ".name") || !my_strcmp(line, ".comment")) {
        return get_header(line, header, 0);
    }
    if (my_strstr(line, LABEL_STR)) {
        if (check_label(line, saved_labels)) {
            return 1;
        }
        label = 2;
    }
    fill_args(args, line, label);
    if (label && !args[0]) {
        label = 1;
        return 0;
    }
    if (parse_args(args, saved_labels, label)) {
        return 1;
    }
    label = 0;
    return 0;
}

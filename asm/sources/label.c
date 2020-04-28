/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** label
*/

#include "label.h"
#include "op.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

static int check_errors(char *line);

static int check_duplicate(char **labels, int nb_labels);

int check_label(char *line, labels_t *saved_labels)
{
    char **labels = saved_labels->labels;
    int nb_labels = saved_labels->nb_labels;

    if (check_errors(line)) {
        return 1;
    }
    labels = realloc(labels, sizeof(char *) * ((size_t) nb_labels + 2));
    if (!labels) {
        return 1;
    }
    saved_labels->labels = labels;
    labels[nb_labels + 1] = NULL;
    labels[nb_labels] = my_strndup(line, my_strcspn(line, LABEL_STR));
    if (!labels[nb_labels]) {
        return 1;
    }
    saved_labels->nb_labels++;
    if (check_duplicate(labels, nb_labels)) {
        return 1;
    }
    return 0;
}

static int check_errors(char *line)
{
    if (LABEL_CHAR == line[0]) {
        write(2, "Unnamed label.\n", 15);
        return 1;
    }
    if (my_strstr(line, LABEL_STR)[1]) {
        write(2, "Invalid instruction.\n", 21);
        return 1;
    }
    if (my_strspn(line, LABEL_CHARS) != my_strlen(line) - 1){
        write(2, "Unauthorized character in label.\n", 33);
        return 1;
    }
    return 0;
}

static int check_duplicate(char **labels, int nb_labels)
{
    int i = 0;

    while (i < nb_labels - 1) {
        if (!my_strcmp(labels[i], labels[nb_labels])) {
            write(2, "Label declared multiple times.\n", 31);
            return 1;
        }
        i++;
    }
    return 0;
}

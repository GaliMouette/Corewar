/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** add_label
*/

#include "asm/add_label.h"

int add_label(char * line, labels_t *saved_labels)
{
    char **labels = saved_labels->labels;
    int nb_labels = saved_labels->nb_labels;

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
    return 0;
}

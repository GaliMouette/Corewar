/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** label
*/

#include "asm/label.h"

int check_label(char *line, labels_t *saved_labels, int label)
{
    char **labels = saved_labels->labels;
    int nb_labels = saved_labels->nb_labels;

    if (check_errors(line)) {
        return 1;
    }
    if (1 == label) {
        if(extend_label(labels, nb_labels, line)) {
            return 1;
        }
    } else {
        if (add_label(line, saved_labels)) {
            return 1;
        }
    }
    if (check_duplicate(saved_labels->labels, saved_labels->nb_labels)) {
        return 1;
    }
    return 0;
}

static int extend_label(char **labels, int nb_labels, char *line)
{
    int dest_len = my_strlen(labels[nb_labels - 1]);
    int src_len = my_strcspn(line, LABEL_STR);
    size_t len = (size_t) (dest_len + src_len + 2);
    char *new_label = realloc(labels[nb_labels - 1], len);

    if (!new_label) {
        return 1;
    }
    labels[nb_labels - 1] = new_label;
    new_label[dest_len] = ' ';
    my_memcpy(new_label + dest_len + 1, line, src_len);
    new_label[dest_len + src_len + 1] = '\0';
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
    char *last_label = labels[nb_labels - 1];
    char *label = labels[i];

    while (last_label && my_strstr(last_label, " ")) {
        last_label += my_strcspn(last_label, " ") + 1;
    }
    while (label && last_label && i < nb_labels) {
        label = labels[i];
        if (my_strstr(label, " ")) {
            if (check_label_space(label, last_label)) {
                return 1;
            }
        } else if (label != last_label && !my_strcmp(label, last_label)) {
            write(2, "Label declared multiple times.\n", 31);
            return 1;
        }
        i++;
    }
    return 0;
}

static int check_label_space(char *label, char *last_label)
{
    int label_len;
    int last_len;

    while (*label) {
        label += (' ' == label[0]);
        label_len = my_strcspn(label, " ");
        last_len = my_strlen(last_label);
        if (label == last_label) {
            label += my_strcspn(label, " ");
            continue;
        }
        if (label_len == last_len && !my_strncmp(label, last_label, label_len)){
            write(2, "Label declared multiple times.\n", 31);
            return 1;
        }
        label += my_strcspn(label, " ");
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** label
*/

#ifndef LABEL_H_
#define LABEL_H_

struct __attribute__((packed)) labels_s
{
    char **labels;
    int nb_labels;
};

typedef struct labels_s labels_t;

int check_label(char *line, labels_t *saved_labels);

#endif /* !LABEL_H_ */

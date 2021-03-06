/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** label
*/

#ifndef LABEL_H_
#define LABEL_H_

#include "typedefs/labels_t.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

int check_label(char *line, labels_t *saved_labels);
static int check_errors(char *line);
static int check_duplicate(char **labels, int nb_labels);

#endif /* !LABEL_H_ */

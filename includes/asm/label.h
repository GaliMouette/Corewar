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

int check_label(char *line, labels_t *saved_labels, int label);
static int extend_label(char **labels, int nb_labels, char *line);
static int check_errors(char *line);
static int check_duplicate(char **labels, int nb_labels);
static int check_label_space(char *label, char *last_label);

//  Using
int add_label(char * line, labels_t *saved_labels);

#endif /* !LABEL_H_ */

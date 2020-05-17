/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** replace_labels
*/

#ifndef REPLACE_LABELS_H_
#define REPLACE_LABELS_H_

#include "typedefs/instruction_t.h"
#include "utils.h"
#include <unistd.h>

int replace_labels(instruction_t *head, long prog_size);
static int set_pc(instruction_t *head,
instruction_t *dummy, int info[2], long prog_size);
static int get_label_pc(instruction_t *dummy, char *label, long prog_size);
static int get_label_space(char *dummy, char *label);

//  Using
char *last_label(char *new_label, int set);

#endif /* !REPLACE_LABELS_H_ */

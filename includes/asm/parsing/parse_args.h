/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parse_args
*/

#ifndef PARSE_ARGS_H_
#define PARSE_ARGS_H_

#include "op.h"
#include "typedefs/labels_t.h"
#include "typedefs/instruction_t.h"
#include "typedefs/header_t.h"
#include "utils.h"
#include <unistd.h>

int parse_args
(char *args[6], labels_t *saved_labels, int *label, instruction_t **head);
static int get_mnemonique_index(char *arg);
static int check_errors(char *args[6], int index);

//  Using
int get_header(char *line, header_t *header, int is_set);
int check_nb_args(char *args[6], int index);
int check_args_types(char *args[6], int index);
int add_instruction
(char *args[6], instruction_t **head, int info[2], labels_t *saved_labels);

#endif /* !PARSE_ARGS_H_ */

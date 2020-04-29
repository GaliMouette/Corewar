/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** parse_file
*/

#ifndef PARSE_FILE_H_
#define PARSE_FILE_H_

#include "typedefs/header_t.h"
#include "typedefs/instruction_t.h"
#include "typedefs/labels_t.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int parse_file(FILE *file, header_t *header, instruction_t **head);
static int parse_line
(char *line, header_t *header, labels_t *saved_labels, instruction_t **head);
static void fill_args(char *args[6], char *line, int label);

//  Using
int clean_line(char *line);
int get_header(char *line, header_t *header, int is_set);
int check_label(char *line, labels_t *saved_labels);
int parse_args
(char *args[6], labels_t *saved_labels, int *label, instruction_t **head);

#endif /* !PARSE_FILE_H_ */

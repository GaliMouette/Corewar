/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** add_instruction
*/

#ifndef ADD_INSTRUCTION_H_
#define ADD_INSTRUCTION_H_

#include "typedefs/instruction_t.h"
#include "typedefs/labels_t.h"
#include "utils.h"
#include <stdlib.h>

int add_instruction(char *args[6], instruction_t **head,
int info[2], labels_t *saved_labels);
static int set_instruction(char *args[6], int info[2],
labels_t *saved_labels, instruction_t *new);
static int set_args(char *args[6], instruction_t *new);
static int set_direct_or_indirect(char *args[6],
instruction_t *new, int i, int direct);
static int set_label(char *args[6], instruction_t *new, int i, int direct);

//  Using
int get_args_types(char *args[6]);

#endif /* !ADD_INSTRUCTION_H_ */

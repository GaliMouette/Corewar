/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** compile_file
*/

#ifndef COMPILE_FILE_H_
#define COMPILE_FILE_H_

#include "typedefs/header_t.h"
#include "typedefs/instruction_t.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int compile_file(char const *path);
static FILE *open_file(char const *path);
static void free_instruction(instruction_t *head);

//  Using
int parse_file(FILE *file, header_t *header, instruction_t **head);
long calculate_pc(instruction_t *head);
int replace_labels(instruction_t *head);
int write_file(char const *path, header_t *header, instruction_t *head);


#endif /* !COMPILE_FILE_H_ */

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** write_instructions
*/

#ifndef WRITE_INSTRUCTIONS_H_
#define WRITE_INSTRUCTIONS_H_

#include "typedefs/instruction_t.h"
#include <unistd.h>

void write_instructions(instruction_t *head, int fd);
static int write_special(instruction_t *head, int fd);
static int write_short(instruction_t *head, int fd);
static void write_simple(instruction_t *head, int fd);

//  Using
void reverse_write(int fd, const void *buf, int n);

#endif /* !WRITE_INSTRUCTIONS_H_ */

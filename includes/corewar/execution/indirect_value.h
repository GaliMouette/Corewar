/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** indirect_value
*/

#ifndef INDIRECT_VALUE_H_
#define INDIRECT_VALUE_H_

#include "typedefs/arena_t.h"

void get_indirect_value(arena_t *arena, int address, int read_size, int *value);
void set_indirect_value(arena_t *arena, int address, int write_size, int value);

#endif /* !INDIRECT_VALUE_H_ */

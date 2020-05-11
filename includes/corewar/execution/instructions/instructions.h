/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include "typedefs/arena_t.h"

int add(arena_t *arena, int i);
int and(arena_t *arena, int i);
int ld(arena_t *arena, int i);
int ldi(arena_t *arena, int i);
int or(arena_t *arena, int i);
int st(arena_t *arena, int i);
int sti(arena_t *arena, int i);
int sub(arena_t *arena, int i);
int xor(arena_t *arena, int i);

//  Using
void set_opterm(int *term, arena_t *arena, int i, int j);
void get_indirect_value(arena_t *arena, int address, int read_size, int *value);
void set_indirect_value(arena_t *arena, int address, int write_size, int value);

#endif /* !INSTRUCTIONS_H_ */

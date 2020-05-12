/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include "typedefs/arena_t.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

int add_instruction(arena_t *arena, int i);
int aff_instruction(arena_t *arena, int i);
int and_instruction(arena_t *arena, int i);
int fork_instruction(arena_t *arena, int i);
int ld_instruction(arena_t *arena, int i);
int ldi_instruction(arena_t *arena, int i);
int lfork_instruction(arena_t *arena, int i);
int live_instruction(arena_t *arena, int i);
int lld_instruction(arena_t *arena, int i);
int lldi_instruction(arena_t *arena, int i);
int or_instruction(arena_t *arena, int i);
int st_instruction(arena_t *arena, int i);
int sti_instruction(arena_t *arena, int i);
int sub_instruction(arena_t *arena, int i);
int xor_instruction(arena_t *arena, int i);
int zjmp_instruction(arena_t *arena, int i);

//  Using
void set_term(int *term, arena_t *arena, int i, int j);
void get_indirect_value(arena_t *arena, int address, int read_size, int *value);
void set_indirect_value(arena_t *arena, int address, int write_size, int value);

#endif /* !INSTRUCTIONS_H_ */

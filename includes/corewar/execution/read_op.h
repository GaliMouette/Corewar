/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** read_op
*/

#ifndef READ_OP_H_
#define READ_OP_H_

#include "typedefs/arena_t.h"
#include "op.h"

int read_op(arena_t *arena, int i, loaded_op_t *loaded_op);
static void get_args_type(arena_t *arena, int i, loaded_op_t *loaded_op);
static void fill_args_type(loaded_op_t *loaded_op, int opcode, int coding_byte);
static void get_args(arena_t *arena, int i, loaded_op_t *loaded_op);
static int check_args(loaded_op_t *loaded_op);

#endif /* !READ_OP_H_ */

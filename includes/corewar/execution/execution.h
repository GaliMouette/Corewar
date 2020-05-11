/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#ifndef EXECUTION_H_
#define EXECUTION_H_

#include "typedefs/arena_t.h"

int execution(arena_t *arena);
void get_opcode(arena_t *arena, int i, operation_t *exec);
int check_opcode(int opcode, operation_t *exec);
void fill_args_type(operation_t *exec, int opcode, int coding_byte);
void get_args_type(arena_t *arena, int i, operation_t *exec);
void get_args(arena_t *arena, int i, operation_t *exec);

#endif /* !EXECUTION_H_ */

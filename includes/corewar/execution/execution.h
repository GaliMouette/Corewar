/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#ifndef EXECUTION_H_
#define EXECUTION_H_

#include "corewar/execution/instructions/instructions.h"
#include "typedefs/arena_t.h"

int execution(arena_t *arena, long dump);
static int execute_current_cycle(arena_t *arena);
static void reset_loaded_op(loaded_op_t *loaded_op);
static int remove_dead(arena_t *arena);
static int remove_execs(arena_t *arena, int i);

//  Using
int read_op(arena_t *arena, int i, loaded_op_t *loaded_op);
void check_winner(arena_t *arena, int *winner, int set_last_alive);
void display_winner(arena_t *arena, int winner);
void dump_memory(arena_t *arena);

#endif /* !EXECUTION_H_ */

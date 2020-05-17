/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#ifndef EXECUTION_H_
#define EXECUTION_H_

#define CHECK_CYCLE_TO_DIE \
check_winner(arena, &winner, 0); \
if (remove_dead(arena)) { \
    return 1; \
}

#define EXECUTE_INSTRUCTION \
if (instructions[loaded_op->opcode - 1](arena, i)) { \
    return 1; \
} \
arena->execs[i]->pc += loaded_op->pc_offset; \
reset_loaded_op(loaded_op);

#define LOAD_INSTRUCTION \
reset_loaded_op(loaded_op); \
if (read_op(arena, i, loaded_op)) { \
    arena->execs[i]->pc++; \
} else { \
    loaded_op->is_op_loaded = 1; \
}

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

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** execution
*/

#include "corewar/execution/execution.h"

int execution(arena_t *arena, long dump)
{
    int winner = 0;
    unsigned int *current_cycle = &arena->current_cycle;

    while ((-1 != dump) ? *current_cycle < dump : !(winner)) {
        if (execute_current_cycle(arena)) {
            return 1;
        }
        if (*current_cycle && !(*current_cycle % arena->cycle_to_die)) {
            check_winner(arena, &winner, 0);
            if (remove_dead(arena)) {
                return 1;
            }
        }
        arena->current_cycle++;
    }
    if (-1 != dump) {
        dump_memory(arena);
    } else {
        display_winner(arena, winner);
    }
    return 0;
}

static int execute_current_cycle(arena_t *arena)
{
    loaded_op_t *loaded_op;

    for (int i = 0; arena->execs[i]; i++) {
        loaded_op = &arena->execs[i]->loaded_op;
        if (loaded_op->is_op_loaded && !loaded_op->wait_cycle) {
            if (instructions[loaded_op->opcode - 1](arena, i))
                return 1;
            arena->execs[i]->pc += loaded_op->pc_offset;
            reset_loaded_op(loaded_op);
        } else if (!loaded_op->is_op_loaded) {
            reset_loaded_op(loaded_op);
            if (read_op(arena, i, loaded_op)) {
                arena->execs[i]->pc++;
            } else
                loaded_op->is_op_loaded = 1;
        } else
            loaded_op->wait_cycle--;
        arena->execs[i]->pc %= MEM_SIZE;
    }
    return 0;
}

static void reset_loaded_op(loaded_op_t *loaded_op)
{
    loaded_op->is_op_loaded = 0;
    loaded_op->opcode = 0;
    for (int i = 0; i < 4; i++) {
        loaded_op->args_type[i] = NONE;
        loaded_op->args_size[i] = 0;
        loaded_op->args[i] = 0;
    }
    loaded_op->pc_offset = 0;
    loaded_op->wait_cycle = 0;
}

static int remove_dead(arena_t *arena)
{
    for (int i = 0; i < 4; i++) {
        if (arena->players[i].status == DEAD){
            if (remove_execs(arena, i)) {
                return 1;
            }
        } else {
            arena->players[i].status = DEAD;
        }
    }
    return 0;
}

static int remove_execs(arena_t *arena, int i)
{
    size_t index = 0;

    for (int j = 0; arena->execs[j]; j++) {
        if (i + 1 == arena->execs[j]->player) {
            free(arena->execs[j]);
            arena->execs[j] = NULL;
        } else {
            arena->execs[index] = arena->execs[j];
            index++;
        }
    }
    arena->execs = realloc(arena->execs, sizeof(*arena->execs) * (index + 1));
    if (!arena->execs) {
        return 1;
    }
    arena->execs[index] = NULL;
    return 0;
}

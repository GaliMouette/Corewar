/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#include "corewar/execution/execution.h"

void reset_loaded_op(loaded_op_t *loaded_op)
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

void execute_current_cycle(arena_t *arena)
{
    loaded_op_t *loaded_op;

    for (int i = 0; arena->execs[i]; i++) {
        loaded_op = &arena->execs[i]->loaded_op;
        if (loaded_op->is_op_loaded && !loaded_op->wait_cycle) {
            instructions[loaded_op->opcode - 1](arena, i);
            arena->execs[i]->pc += loaded_op->pc_offset;
            reset_loaded_op(loaded_op);
        } else if (!loaded_op->is_op_loaded) {
            reset_loaded_op(loaded_op);
            if (read_op(arena, i, loaded_op)) {
                arena->execs[i]->pc++;
            } else {
                loaded_op->is_op_loaded = 1;
            }
        } else {
            loaded_op->wait_cycle--;
        }
        arena->execs[i]->pc %= MEM_SIZE;
    }
}

int remove_execs(arena_t *arena, int i)
{
    int index = 0;

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

void check_la_mort(arena_t *arena, int *winner)
{
    int players_alive = 0;

    for (int i = 0; i < 4; i++) {
        if (arena->players[i].status == ALIVE) {
            players_alive++;
            *winner = arena->players[i].number;
        }
    }
    if (1 != players_alive) {
        *winner = 0;
    }
}

int execution(arena_t *arena)
{
    int winner = 0;

    while (!winner) {
        execute_current_cycle(arena);
        arena->current_cycle++;
        if (arena->current_cycle && !(arena->current_cycle % arena->cycle_to_die)) {
            check_la_mort(arena, &winner);
            for (int i = 0; i < 4; i++) {
                if (arena->players[i].status == DEAD){
                    remove_execs(arena, i);
                } else {
                    arena->players[i].status = DEAD;
                }
            }
        }
    }
    display_winner(arena, winner);
    return 0;
}

int display_winner(arena_t *arena, int winner)
{
    int index = winner - 1;
    char *name  = arena->players[index].name;
    int number = arena->players[index].number;

    write(1, "The player ", 11);
    my_put_nbr(number);
    write (1, " (", 2);
    write(1, name, (size_t) my_strlen(name));
    write(1, ") has won.\n", 11);
    return 0;
}

/*
It must check that each process calls the "live" instruction every CYCLE_TO_DIE cycles.
If, after NBR_LIVE executions of the instruction "live", several processes are still alive, CYCLE_TO_DIE is decreased by CYCLE_DELTA units. This starts over until there are no live processes left.
The last champion to have said “live” wins.
*/

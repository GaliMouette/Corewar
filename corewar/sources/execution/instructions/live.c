/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** live_instruction
*/

#include "corewar/execution/instructions/instructions.h"

// TODO : live_delta décrémenter

int live_instruction(arena_t *arena, int i)
{
    loaded_op_t loaded_op = arena->execs[i]->loaded_op;
    int index = loaded_op.args[0] - 1;
    char *name;

    if (index < 0 || arena->nb_players <= index) {
        return 0;
    }
    name = arena->players[index].name;
    arena->players[index].status = ALIVE;
    write(1, "The player ", 12);
    my_put_nbr(arena->players[index].number);
    write(1, " (", 2);
    write(1, name, (size_t) my_strlen(name));
    write(1, ") is alive.\n", 12);
    return 0;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** live
*/

#include "corewar/execution/instructions/instructions.h"

int live(arena_t *arena, int i)
{
    arena->players[i].status = ALIVE;
    write(1, "The player ", 12);
    my_put_nbr(arena->players[i].number);
    write(1, " (", 2);
    write(1, arena->players[i].name, my_strlen(arena->players[i].name));
    write(1, ") is alive.\n", 12);
    return 0;
}

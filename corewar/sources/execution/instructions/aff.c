/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** aff_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int aff_instruction(arena_t *arena, int i)
{
    int tmp = arena->execs[i]->registry[arena->execs[i]->loaded_op.args[0] - 1];
    int c = tmp % 256;

    if ('!' <= c && c <= '~') {
        write(1, "'", 1);
        write(1, &c, 1);
        write(1, "'\n", 2);
    } else {
        write(1, "aff: character is not printable\n", 32);
    }
    return 0;
}

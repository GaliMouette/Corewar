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
    char c = (char) (tmp % 256);

    write(1, &c, 1);
    return 0;
}

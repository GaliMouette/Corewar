/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** st_instruction
*/

#include "corewar/execution/instructions/instructions.h"

int st_instruction(arena_t *arena, int i)
{
    loaded_op_t loaded_op = arena->execs[i]->loaded_op;
    int result =
    arena->execs[i]->registry[loaded_op.args[0] - 1];
    int address = arena->execs[i]->pc + loaded_op.args[1] % IDX_MOD;

    address %= MEM_SIZE;
    if (loaded_op.args_type[1] == REG_TYPE) {
        arena->execs[i]->registry[loaded_op.args[1] - 1]
        = result;
    } else {
        set_indirect_value(arena, address, REG_SIZE, result);
    }
    return 0;
}

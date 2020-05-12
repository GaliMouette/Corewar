/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** read_op
*/

#include "corewar/execution/read_op.h"

int read_op(arena_t *arena, int i, loaded_op_t *loaded_op)
{
    loaded_op->opcode = arena->memory[arena->execs[i]->carry % MEM_SIZE];
    if (check_opcode(loaded_op)) {
        return 1;
    }
    get_args_type(arena, i, loaded_op);
    get_args(arena, i, loaded_op);
    if (check_args(loaded_op)) {
        return 1;
    }
    return 0;
}

static int check_opcode(loaded_op_t *loaded_op)
{
    int opcode = loaded_op->opcode;

    if (opcode < 0x01 || 0x10 < opcode) {
        return 1;
    } else {
        loaded_op->pc_offset++;
        return 0;
    }
}

static void get_args_type(arena_t *arena, int i, loaded_op_t *loaded_op)
{
    int opcode = loaded_op->opcode;
    char codingbyte = arena->memory[arena->execs[i]->pc + loaded_op->pc_offset];

    if (0x01 == opcode) {
        loaded_op->args_type[0] = DIR_TYPE;
        loaded_op->args_size[0] = 4;
    } else if (0x09 == opcode || 0x0C == opcode || 0x0F == opcode) {
        loaded_op->args_type[0] = IND_TYPE;
        loaded_op->args_size[0] = 2;
    } else {
        fill_args_type(loaded_op, opcode, codingbyte);
        loaded_op->pc_offset++;
    }
}

static void fill_args_type(loaded_op_t *loaded_op, int opcode, int coding_byte)
{
    for (int j = 0; j < 4; j++) {
        loaded_op->args_type[j] = coding_byte >> (8 - (j + 1) * 2) & 3;
        switch (loaded_op->args_type[j]) {
        case REG_TYPE:
            loaded_op->args_size[j] = 1;
            break;
        case DIR_TYPE:
            loaded_op->args_size[j] =
            (0x0A == opcode || 0x0B == opcode || 0x0E == opcode) ? 2 : 4;
            break;
        case IND_TYPE:
            loaded_op->args_size[j] = 2;
            break;
        }
    }
}

static void get_args(arena_t *arena, int i, loaded_op_t *loaded_op)
{
    for (int j = 0; j < 3; j++) {
        if (loaded_op->args_size[j] == 1) {
            loaded_op->args[j] =
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset];
        }
        if (loaded_op->args_size[j] == 2) {
            loaded_op->args[j] =
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset] << 4|
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset + 1];
        }
        if (loaded_op->args_size[j] == 4) {
            loaded_op->args[j] =
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset]     << 12|
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset + 1] << 8 |
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset + 2] << 4 |
            arena->memory[arena->execs[i]->pc + loaded_op->pc_offset + 3];
        }
        loaded_op->pc_offset += loaded_op->args_size[j];
    }
}

static int check_args(loaded_op_t *loaded_op)
{
    int index = loaded_op->opcode - 1;

    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        if (loaded_op->args_type[i] == 3 && op_tab[index].type[i] == 4) {
            continue;
        }
        if (!(loaded_op->args_type[i] & (unsigned int) op_tab[index].type[i])) {
            return 1;
        }
        if (loaded_op->args_type[i] == 1) {
            if (loaded_op->args[i] < 1 || REG_NUMBER < loaded_op->args[i]) {
                return 1;
            }
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#include "corewar/execution/execution.h"

void get_opcode(arena_t *arena, int i, operation_t *operation)
{
    operation->opcode = arena->memory[arena->execs[i]->carry % MEM_SIZE];
}

int check_opcode(int opcode, operation_t *operation)
{
    if (opcode < 0x01 || 0x10 < opcode) {
        return 1;
    } else {
        operation->pc_offset++;
        return 0;
    }
}

void fill_args_type(operation_t *operation, int opcode, int coding_byte)
{
    for (int j = 0; j < 4; j++) {
        switch (coding_byte >> (8 - (j + 1) * 2) & 3) {
        case 1:
            operation->args_type[j] = 1;
            break;
        case 2:
            operation->args_type[j] =
            (0x0A == opcode || 0x0B == opcode || 0x0E == opcode) ? 2 : 4;
            break;
        case 3:
            operation->args_type[j] = 2;
            break;
        default:
            operation->args_type[j] = coding_byte >> (8 - (j + 1) * 2) & 3;
            break;
        }
    }
}

void get_args_type(arena_t *arena, int i, operation_t *operation)
{
    int opcode = operation->opcode;
    char coding_byte = arena->memory[arena->execs[i]->pc + operation->pc_offset];

    if (0x01 == opcode) {
        operation->args_type[0] = 4;
    } else if (0x09 == opcode || 0x0C == opcode || 0x0F == opcode) {
        operation->args_type[0] = 2;
    } else {
        fill_args_type(operation, opcode, coding_byte);
        operation->pc_offset++;
    }
}

void get_args(arena_t *arena, int i, operation_t *operation)
{
    for (int j = 0; j < 3; j++) {
        if (operation->args_type[j] == 1) {
            operation->args[j] =
            arena->memory[arena->execs[i]->pc + operation->pc_offset];
        }
        if (operation->args_type[j] == 2) {
            operation->args[j] =
            arena->memory[arena->execs[i]->pc + operation->pc_offset] << 4|
            arena->memory[arena->execs[i]->pc + operation->pc_offset + 1];
        }
        if (operation->args_type[j] == 4) {
            operation->args[j] =
            arena->memory[arena->execs[i]->pc + operation->pc_offset]     << 12|
            arena->memory[arena->execs[i]->pc + operation->pc_offset + 1] << 8 |
            arena->memory[arena->execs[i]->pc + operation->pc_offset + 2] << 4 |
            arena->memory[arena->execs[i]->pc + operation->pc_offset + 3];
        }
        operation->pc_offset += operation->args_type[j];
    }
}

int execution(arena_t *arena)
{
    operation_t *dummy;

    for (int i = 0; arena->execs[i]; i++) {
        dummy = &arena->execs[i]->operation;
        // Si pas operation cycle alors executer operation puis read suivante
        // Sinon décrémenter cycle
        get_opcode(arena, i, dummy);
        if (check_opcode(dummy->opcode, dummy)) {
            continue;
        }
        // TODO : Gestion erreur sur type arguments
        get_args_type(arena, i, dummy);
        get_args(arena, i, dummy);
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** execution
*/

#include "corewar/execution/execution.h"

void get_opcode(arena_t *arena, int i, instruction_t *instruction)
{
    instruction->opcode = arena->memory[arena->execs[i]->carry % MEM_SIZE];
}

int check_opcode(int opcode, instruction_t *instruction)
{
    if (opcode < 0x01 || 0x10 < opcode) {
        return 1;
    } else {
        instruction->pc_offset++;
        return 0;
    }
}

void fill_args_type(instruction_t *instruction, int opcode, int coding_byte)
{
    for (int j = 0; j < 4; j++) {
        switch (coding_byte >> (8 - (j + 1) * 2) & 3) {
        case 1:
            instruction->args_type[j] = 1;
            break;
        case 2:
            instruction->args_type[j] =
            (0x0A == opcode || 0x0B == opcode || 0x0E == opcode) ? 2 : 4;
            break;
        case 3:
            instruction->args_type[j] = 2;
            break;
        default:
            instruction->args_type[j] = coding_byte >> (8 - (j + 1) * 2) & 3;
            break;
        }
    }
}

void get_args_type(arena_t *arena, int i, instruction_t *instruction)
{
    int opcode = instruction->opcode;
    char coding_byte = arena->memory[arena->execs[i]->pc + instruction->pc_offset];

    if (0x01 == opcode) {
        instruction->args_type[0] = 4;
    } else if (0x09 == opcode || 0x0C == opcode || 0x0F == opcode) {
        instruction->args_type[0] = 2;
    } else {
        fill_args_type(instruction, opcode, coding_byte);
        instruction->pc_offset++;
    }
}

void get_args(arena_t *arena, int i, instruction_t *instruction)
{
    for (int j = 0; j < 3; j++) {
        if (instruction->args_type[j] == 1) {
            instruction->args[j] =
            arena->memory[arena->execs[i]->pc + instruction->pc_offset];
        }
        if (instruction->args_type[j] == 2) {
            instruction->args[j] =
            arena->memory[arena->execs[i]->pc + instruction->pc_offset]         |
            arena->memory[arena->execs[i]->pc + instruction->pc_offset + 1] << 2;
        }
        if (instruction->args_type[j] == 4) {
            instruction->args[j] =
            arena->memory[arena->execs[i]->pc + instruction->pc_offset]          |
            arena->memory[arena->execs[i]->pc + instruction->pc_offset + 1] << 2 |
            arena->memory[arena->execs[i]->pc + instruction->pc_offset + 2] << 4 |
            arena->memory[arena->execs[i]->pc + instruction->pc_offset + 3] << 6;
        }
        instruction->pc_offset += instruction->args_type[j];
    }
}

int execution(arena_t *arena)
{
    instruction_t *dummy;

    for (int i = 0; arena->execs[i]; i++) {
        dummy = &arena->execs[i]->instruction;
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

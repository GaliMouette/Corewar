/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** indirect_value
*/

#include "corewar/execution/indirect_value.h"

void get_indirect_value(arena_t *arena, int address, int read_size, int *value)
{
    int shift = 0;
    int offset = 0;

    *value = 0;
    for (int i = 0; i < read_size; i++) {
        shift = (read_size - (i + 1)) * 8;
        offset = (address + i) % MEM_SIZE;
        *value |= arena->memory[offset] << shift & 0xff << shift;
    }
}

void set_indirect_value(arena_t *arena, int address, int write_size, int value)
{
    int shift = 0;
    int offset = 0;

    for (int i = 0; i < write_size; i++) {
        shift = (write_size - (i + 1)) * 8;
        offset = (address + i) % MEM_SIZE;
        arena->memory[offset] = (char) (value >> shift & 0xff);
    }
}

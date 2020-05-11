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

    *value = 0;
    for (int i = 0; i < read_size; i++) {
        shift = (read_size - (i + 1)) * 4;
        *value |= arena->memory[(address + i) % MEM_SIZE] << shift;
    }
}

void set_indirect_value(arena_t *arena, int address, int write_size, int value)
{
    int shift = 0;

    for (int i = 0; i < write_size; i++) {
        shift = (write_size - (i + 1)) * 4;
        arena->memory[(address + i) % MEM_SIZE] = (char) (value >> shift & 0xf);
    }
}

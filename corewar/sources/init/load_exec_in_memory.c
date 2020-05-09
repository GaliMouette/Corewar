/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** load_exec_in_memory
*/

#include "corewar/init/load_exec_in_memory.h"

int load_exec_in_memory(init_t *init, arena_t *arena, int i)
{
    char *buffer;
    int address = init->champs[i].load_address;
    int overflow = address + (int) init->champs[i].header.prog_size;
    int j = 0;

    if (fill_buffer(&buffer, init, i)) {
        return 1;
    }
    if (overflow > MEM_SIZE) {
        while (j < init->champs[i].header.prog_size && (j + address) < MEM_SIZE)
            arena->memory[address++] = buffer[j++];
        address = 0;
        while (j < init->champs[i].header.prog_size)
            arena->memory[address++] = buffer[j++];
    }
    else {
        while (j < init->champs[i].header.prog_size)
            arena->memory[address++] = buffer[j++];
    }
    return 0;
}

static int fill_buffer(char **buffer, init_t *init, int i)
{
    *buffer = malloc((size_t) init->champs[i].header.prog_size);
    if (!buffer) {
        return 1;
    }
    read(init->champs[i].file_desc, buffer,
    (size_t) init->champs[i].header.prog_size);
    return 0;
}

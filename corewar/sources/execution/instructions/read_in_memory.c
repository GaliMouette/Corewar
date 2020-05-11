/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** read_in_memory
*/

#include "corewar/execution/instructions/read_in_memory.h"

void read_in_memory(char *memory, int position, int size, int *result)
{
    for (int i = 0; i < size; i++) {
        *result = (int) BSWAP_INT((unsigned char) memory[position]);
    }
}

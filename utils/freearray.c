/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** freearray
*/

#include "utils.h"
#include <stdlib.h>

void freearray(void **array)
{
    if (!array) {
        return;
    }
    for (int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

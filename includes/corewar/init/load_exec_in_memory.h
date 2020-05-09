/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** load_exec_in_memory
*/

#ifndef LOAD_EXEC_IN_MEMORY_H_
#define LOAD_EXEC_IN_MEMORY_H_

#include "typedefs/arena_t.h"
#include "typedefs/init_t.h"
#include <stdlib.h>
#include <unistd.h>

int load_exec_in_memory(init_t *init, arena_t *arena, int i);
static int fill_buffer(char **buffer, init_t *init, int i);

#endif /* !LOAD_EXEC_IN_MEMORY_H_ */

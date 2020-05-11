/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ldi
*/

#ifndef LDI_H_
#define LDI_H_

#include "typedefs/arena_t.h"

int ldi(arena_t *arena, int i);

//  Using
void set_operation_terms(int *term1, int *term2, arena_t *arena, int i);
void read_in_memory(char *memory, int position, int size, int *result);

#endif /* !LDI_H_ */

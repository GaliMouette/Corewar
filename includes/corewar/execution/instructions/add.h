/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add
*/

#ifndef ADD_H_
#define ADD_H_

#include "typedefs/arena_t.h"
#include <limits.h>

#define ADD_OVERFLOW(a, b) (a > INT_MAX - b || a < INT_MIN - b) ? -1 : a + b

int add(arena_t *arena, int i);

#endif /* !ADD_H_ */

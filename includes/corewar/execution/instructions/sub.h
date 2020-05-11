/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** sub
*/

#ifndef SUB_H_
#define SUB_H_

#include "typedefs/arena_t.h"
#include <limits.h>

#define SUB_OVERFLOW(a, b) (a > INT_MAX + b || a < INT_MAX + b) ? -1 : a - b

int sub(arena_t *arena, int i);

#endif /* !SUB_H_ */

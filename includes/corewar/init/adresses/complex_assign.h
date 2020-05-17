/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** complex_assign
*/

#ifndef COMPLEX_ASSIGN_H_
#define COMPLEX_ASSIGN_H_

#include "typedefs/arena_t.h"
#include "typedefs/init_t.h"

#define SWAP(a, b) \
int tmp = a; \
a = b; \
b = tmp;

#define SORT(a, b, c) \
if ((a) > (b)) { SWAP(a, b); } \
if ((a) > (c)) { SWAP(a, c); } \
if ((b) > (c)) { SWAP(b, c); }

#define CHOICE(choice, address)     ((choice == address) ? MEM_SIZE : 0)

void complex_assign(init_t *init, arena_t *arena, int already_set);
static void get_addresses(init_t *init, int addresses[3]);
static void set_third_address(int address[3]);
static void set_fourth_address(init_t *init, int i, int address[3]);

#endif /* !COMPLEX_ASSIGN_H_ */

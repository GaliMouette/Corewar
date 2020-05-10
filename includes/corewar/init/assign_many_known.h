/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** assign_many_known
*/

#ifndef ASSIGN_MANY_KNOWN_H_
#define ASSIGN_MANY_KNOWN_H_

#include "typedefs/init_t.h"

#define MEM_SIZE                    (6 * 1024)

#define SWAP(a,b)                   int tmp = a; a = b; b = tmp;

#define SORT(a,b,c) \
                                    if ((a) > (b)) { SWAP(a,b); } \
                                    if ((a) > (c)) { SWAP(a,c); } \
                                    if ((b) > (c)) { SWAP(b,c); } \

#define CHOICE(choice, address)     ((choice == address) ? MEM_SIZE : 0)

void assign_many_known(init_t *init, int nb_players, int nb_known);
static void get_load_address(init_t *init, int nb_players, int address[3]);
static void set_third_unknown(int address[3]);
static void  set_fourth_unknown(init_t *init, int i, int address[3]);

#endif /* !ASSIGN_MANY_KNOWN_H_ */

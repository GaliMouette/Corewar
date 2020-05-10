/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** assign_default_address
*/

#ifndef ASSIGN_DEFAULT_ADDRESS_H_
#define ASSIGN_DEFAULT_ADDRESS_H_

#include "typedefs/init_t.h"

#define MEM_SIZE        (6 * 1024)

void assign_default_address(init_t *init, int nb_players);
static void init_useful_var(init_t *init, int nb_players, int *nb_known);
static void assign_little_known(init_t *init, int nb_players);

// Using
int count_players(init_t *init);
void assign_many_known(init_t *init, int nb_players, int nb_known);

#endif /* !ASSIGN_DEFAULT_ADDRESS_H_ */

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_name
*/

#ifndef GET_NAME_H_
#define GET_NAME_H_

#include "typedefs/header_t.h"
#include "utils.h"
#include <unistd.h>

int get_name(char *args, header_t *header, int is_set);
static int check_errors(char *args, int set);

#endif /* !GET_NAME_H_ */

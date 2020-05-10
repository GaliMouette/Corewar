/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_load
*/

#ifndef SET_LOAD_H_
#define SET_LOAD_H_

#include "typedefs/init_t.h"
#include "utils.h"
#include <unistd.h>

int set_load_address(char const *arg, int *i, init_t *init, int champion);
static int check_error(char const *arg, init_t *init, int champion);
static int is_hex(char const *arg);

#endif /* !SET_LOAD_H_ */

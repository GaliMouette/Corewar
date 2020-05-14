/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_dump
*/

#ifndef SET_DUMP_H_
#define SET_DUMP_H_

#include "typedefs/init_t.h"
#include "utils.h"
#include <unistd.h>

int set_dump(char const *arg, init_t *init);
static int check_error(char const *arg, init_t *init);

#endif /* !SET_DUMP_H_ */

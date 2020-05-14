/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_prog_nbr
*/

#ifndef SET_PROG_NBR_H_
#define SET_PROG_NBR_H_

#include "typedefs/init_t.h"
#include "utils.h"
#include <unistd.h>

int set_prog_nbr(char const *arg, int *i, init_t *init, int champion);
static ssize_t check_error(char const *arg, init_t *init, int champion);

#endif /* !SET_PROG_NBR_H_ */

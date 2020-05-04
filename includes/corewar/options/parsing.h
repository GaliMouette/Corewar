/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** parsing
*/

#ifndef PARSING_H_
#define PARSING_H_

#include "typedefs/init_t.h"
#include "utils.h"
#include <unistd.h>

int parse_args(char const *argv[], init_t *init);
static int set_prog_args(char const *argv[], int *i, init_t *init, int *index);

//  Using
int set_dump(char const *arg, init_t *init);
int set_prog_nbr(char const *arg, int *i, init_t *init, int champion);
int set_load_address(char const *arg, int *i, init_t *init, int champion);

#endif /* !PARSING_H_ */

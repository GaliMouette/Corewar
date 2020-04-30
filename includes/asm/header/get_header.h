/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_header
*/

#ifndef GET_HEADER_H_
#define GET_HEADER_H_

#include "typedefs/header_t.h"
#include "utils.h"
#include <unistd.h>

int get_header(char *line, header_t *header, int is_set);
static int check_errors(char *args);

//  Using
int get_name(char *args, header_t *header, int is_set);
int get_comment(char *args, header_t *header, int is_set);

#endif /* !GET_HEADER_H_ */

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_comment
*/

#ifndef GET_COMMENT_H_
#define GET_COMMENT_H_

#include "header_t.h"
#include "utils.h"
#include <unistd.h>

int get_comment(char *args, header_t *header, int is_set);
static int check_errors(char *args, int set);

//  Using
int get_name(char *args, header_t *header, int is_set);

#endif /* !GET_COMMENT_H_ */

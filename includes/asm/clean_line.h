/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** clean_line
*/

#ifndef CLEAN_LINE_H_
#define CLEAN_LINE_H_

#include "utils.h"

#define COMMENT_CHAR '#'
#define COMMENT_STR "#"

int clean_line(char *line);
static int remove_comment(char *line);
static void remove_tabulations(char *line);
static void remove_comas(char *line);
static void remove_spaces(char *line);

#endif /* !CLEAN_LINE_H_ */

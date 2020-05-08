/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "typedefs/arena_t.h"
#include "typedefs/init_t.h"
#include "utils.h"
#include <unistd.h>

#define USAGE \
"USAGE\
\n./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\
\nDESCRIPTION\
\n-dump nbr_cycle dumps the memory after \
the nbr_cycle execution (if the round isn't\
already over) with the following format: 32 bytes/line\
in hexadecimal (A0BCDEFE1DD3...)\
\n-n prog_number sets the next program's number. \
By default, the first free number in the parameter order\
\n-a load_address sets the next program's loading address. When no address is\
specified, optimize the addresses so that the processes are as far\
away from each other as possible. The addresses are MEM_SIZE modulo.\
\n"

static int initiate(char const *argv[], init_t *init);

// Using
int parse_args(char const *argv[], init_t *init);
int check_files(init_t *init);
int open_files(init_t *init);

#endif /* !MAIN_H_ */

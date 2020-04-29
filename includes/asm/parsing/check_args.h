/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** check_args
*/

#ifndef CHECK_ARGS_H_
#define CHECK_ARGS_H_

#include "op.h"
#include "typedefs/labels_t.h"
#include "utils.h"
#include <unistd.h>

#define DIRECT_CHAR '%'
#define REG_NUMBER  16  //  Number of registres (From 1 to 16)

int check_nb_args(char *args[6], int index);
int check_args_types(char *args[6], int index);
static int check_registry(char *arg, int op_index, int arg_index);
static int check_direct(char *arg, int op_index, int arg_index);
static int check_indirect(char *arg, int op_index, int arg_index);

#endif /* !CHECK_ARGS_H_ */

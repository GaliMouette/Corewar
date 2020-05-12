/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_check_nb_args
*/

#include "asm/parsing/check_args.h"
#include <criterion/criterion.h>

Test(check_nb_args, wrong_Args_Number_For_Add_Mmemonique)
{
    char *args[6] = {"add", "r1", "r2", "r3", "r4", NULL};
    int opcode_index = 3;

    cr_assert_eq(check_nb_args(args, opcode_index), 1);
}

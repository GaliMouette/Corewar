/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_check_nb_args
*/

#include "asm/parsing/check_args.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(check_nb_args, not_Enough_Arguments, .init=redirect_all_stderr)
{
    char *args[6] = {"add", "r1", "r2", NULL, NULL, NULL};
    int opcode_index = 3;

    cr_assert_eq(check_nb_args(args, opcode_index), 1);
}

Test(check_nb_args, too_Many_Arguments, .init=redirect_all_stderr)
{
    char *args[6] = {"add", "r1", "r2", "r3", "r4", NULL};
    int opcode_index = 3;

    cr_assert_eq(check_nb_args(args, opcode_index), 1);
}

Test(check_nb_args, good_Number_Of_Arguments)
{
    char *args[6] = {"add", "r1", "r2", "r3", NULL, NULL};
    int opcode_index = 3;

    cr_assert_eq(check_nb_args(args, opcode_index), 0);
}

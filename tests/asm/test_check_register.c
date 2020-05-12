/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_check_args_types
*/

#include "asm/parsing/check_args.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(check_args_types, mnemonique_Take_Not_Register, .init=redirect_all_stderr)
{
    char *args[6] = {"live", "r1", NULL, NULL, NULL, NULL};
    int opcode_index = 0;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, register_With_Letter, .init=redirect_all_stderr)
{
    char *args[6] = {"aff", "rko", NULL, NULL, NULL, NULL};
    int opcode_index = 15;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, register_With_Small_Number, .init=redirect_all_stderr)
{
    char *args[6] = {"aff", "r0", NULL, NULL, NULL, NULL};
    int opcode_index = 15;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, register_With_Big_Number, .init=redirect_all_stderr)
{
    char *args[6] = {"aff", "r118218", NULL, NULL, NULL, NULL};
    int opcode_index = 15;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, register_Good)
{
    char *args[6] = {"add", "r1", "r2", "r3", NULL, NULL};
    int opcode_index = 3;

    cr_assert_eq(check_args_types(args, opcode_index), 0);
}

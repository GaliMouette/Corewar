/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_check_direct
*/

#include "asm/parsing/check_args.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(check_args_types, mnemonique_Take_Not_Direct, .init=redirect_all_stderr)
{
    char *args[6] = {"aff", "%23", NULL, NULL, NULL, NULL};
    int opcode_index = 15;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, direct_Good_Label)
{
    char *args[6] = {"fork", "%:abc", NULL, NULL, NULL, NULL};
    int opcode_index = 11;

    cr_assert_eq(check_args_types(args, opcode_index), 0);
}

Test(check_args_types, direct_Bad_Label, .init=redirect_all_stderr)
{
    char *args[6] = {"fork", "%:(oui", NULL, NULL, NULL, NULL};
    int opcode_index = 11;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, direct_With_Letter, .init=redirect_all_stderr)
{
    char *args[6] = {"ld", "%ac", "r1", NULL, NULL, NULL};
    int opcode_index = 1;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, good_Direct)
{
    char *args[6] = {"ld", "%66", "r1", NULL, NULL, NULL};
    int opcode_index = 1;

    cr_assert_eq(check_args_types(args, opcode_index), 0);
}

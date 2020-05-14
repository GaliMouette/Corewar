/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_check_args_types
*/

#include "asm/parsing/check_args.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(check_args_types, mnemonique_Take_Not_Indirect, .init=redirect_all_stderr)
{
    char *args[6] = {"live", "12", NULL, NULL, NULL, NULL};
    int opcode_index = 0;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, indirect_Good_Label)
{
    char *args[6] = {"ld", ":oui", "r10", NULL, NULL, NULL};
    int opcode_index = 1;

    cr_assert_eq(check_args_types(args, opcode_index), 0);
}

Test(check_args_types, indirect_Bad_Label, .init=redirect_all_stderr)
{
    char *args[6] = {"ld", ":(oui", "r10", NULL, NULL, NULL};
    int opcode_index = 1;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, indirect_With_Letter, .init=redirect_all_stderr)
{
    char *args[6] = {"ld", "abc", "r1", NULL, NULL, NULL};
    int opcode_index = 1;

    cr_assert_eq(check_args_types(args, opcode_index), 1);
}

Test(check_args_types, good_Indirect)
{
    char *args[6] = {"ld", "45", "r1", NULL, NULL, NULL};
    int opcode_index = 1;

    cr_assert_eq(check_args_types(args, opcode_index), 0);
}

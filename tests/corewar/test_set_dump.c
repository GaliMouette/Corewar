/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_set_dump
*/

#include "corewar/init/options/set_dump.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(set_dump, already_Good)
{
    init_t init = INIT;

    cr_assert_eq(set_dump("25", &init), 0);
}

Test(set_dump, empty_Argument, .init=redirect_all_stderr)
{
    init_t init = INIT;
    char *arg = NULL;

    cr_assert_eq(set_dump(arg, &init), 1);
}

Test(set_dump, dump_Already_Define, .init=redirect_all_stderr)
{
    init_t init = INIT;
    char *arg = "245";

    init.dump = 23;
    cr_assert_eq(set_dump(arg, &init), 1);
}

Test(set_dump, check_Hexadecimal, .init=redirect_all_stderr)
{
    init_t init = INIT;
    char *tests[6] =
    {"/", ":", "2@", "2G", "2B`", "2Bg"};

    cr_assert_eq(set_dump(tests[0], &init), 1);
    cr_assert_eq(set_dump(tests[1], &init), 1);
    cr_assert_eq(set_dump(tests[2], &init), 1);
    cr_assert_eq(set_dump(tests[3], &init), 1);
    cr_assert_eq(set_dump(tests[4], &init), 1);
    cr_assert_eq(set_dump(tests[5], &init), 1);
}

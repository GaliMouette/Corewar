/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_set_load_address
*/

#include "corewar/init/options/set_load_address.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(set_load_address, already_Good)
{
    init_t init = INIT;
    int i = 1;

    cr_assert_eq(set_load_address("234", &i, &init, 0), 0);
}

Test(set_load_address, address_Already_Define, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;

    init.champs[0].load_address = 3456;
    cr_assert_eq(set_load_address("234", &i, &init, 0), 1);
}

Test(set_load_address, empty_Argument, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;
    char *arg = NULL;

    cr_assert_eq(set_load_address(arg, &i, &init, 0), 1);
}

Test(set_load_address, negative_Argument, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;

    cr_assert_eq(set_load_address("-234", &i, &init, 0), 1);
}

Test(set_load_address, check_Hexadecimal, .init=redirect_all_stderr)
{
    init_t init = INIT;
    char *tests[6] = {"/", ":", "2@", "2G", "2B`", "2Bg"};
    int i = 1;

    cr_assert_eq(set_load_address(tests[0], &i, &init, 0), 1);
    cr_assert_eq(set_load_address(tests[1], &i, &init, 0), 1);
    cr_assert_eq(set_load_address(tests[2], &i, &init, 0), 1);
    cr_assert_eq(set_load_address(tests[3], &i, &init, 0), 1);
    cr_assert_eq(set_load_address(tests[4], &i, &init, 0), 1);
    cr_assert_eq(set_load_address(tests[5], &i, &init, 0), 1);
}

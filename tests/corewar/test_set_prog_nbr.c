/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_set_prog_nbr
*/

#include "corewar/init/options/set_prog_nbr.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(set_prog_nbr, already_Good)
{
    init_t init = INIT;
    int i = 1;

    cr_assert_eq(set_prog_nbr("2", &i, &init, 0), 0);
}

Test(set_prog_nbr, nbr_Already_Define, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;

    init.champs[0].number = 3;
    cr_assert_eq(set_prog_nbr("4", &i, &init, 0), 1);
    cr_assert_eq(set_prog_nbr("3", &i, &init, 1), 1);
}

Test(set_prog_nbr, empty_Argument, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;
    char *arg = NULL;

    cr_assert_eq(set_prog_nbr(arg, &i, &init, 0), 1);
}

Test(set_prog_nbr, argument_Not_Number, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;

    cr_assert_eq(set_prog_nbr("abc", &i, &init, 0), 1);
}

Test(set_prog_nbr, bad_Number, .init=redirect_all_stderr)
{
    init_t init = INIT;
    int i = 1;

    cr_assert_eq(set_prog_nbr("0", &i, &init, 0), 1);
    cr_assert_eq(set_prog_nbr("5", &i, &init, 0), 1);
}

/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_put_nbr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

void my_put_nbr(int number);

Test(my_put_nbr, simple_Number, .init=redirect_all_stdout)
{
    my_put_nbr(42);
    cr_assert_stdout_eq_str("42");
}

Test(my_put_nbr, negative_Number, .init=redirect_all_stdout)
{
    my_put_nbr(-42);
    cr_assert_stdout_eq_str("-42");
}

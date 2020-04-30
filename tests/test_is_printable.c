/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_is_printable.c
*/

#include <criterion/criterion.h>

int is_printable(char const *str);

Test(is_printable, str_With_Printable)
{
    char *str = "Hello";

    cr_assert_eq(is_printable(str), 1);
}

Test(is_printable, str_With_No_Printable)
{
    char *str = "Hello\t";

    cr_assert_eq(is_printable(str), 0);
}

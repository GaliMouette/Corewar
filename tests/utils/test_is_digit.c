/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_is_digit.c
*/

#include <criterion/criterion.h>

int is_digit(char const *str);

Test(is_digit, full_Digit)
{
    char *str = "117443";

    cr_assert_eq(is_digit(str), 1);
}

Test(is_digit, no_Str)
{
    char *str = NULL;

    cr_assert_eq(is_digit(str), 0);
}

Test(is_digit, letter_In_Str)
{
    char *str = "08u83";

    cr_assert_eq(is_digit(str), 0);
}

Test(is_digit, negative_Digit)
{
    char *str = "-117443";

    cr_assert_eq(is_digit(str), 1);
}

Test(is_digit, char_Below_Zero)
{
    cr_assert_eq(is_digit("87.8"), 0);
}

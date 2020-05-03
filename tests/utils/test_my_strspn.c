/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strspn.c
*/

#include "criterion/criterion.h"

int my_strspn(char const *str, char const *chars);

Test(my_strspn, all_Char_Ok)
{
    cr_assert_eq(my_strspn("hello", "ehlo"), 5);
}

Test(my_strspn, char_Different)
{
    cr_assert_eq(my_strspn("hella", "ehlo"), 4);
}

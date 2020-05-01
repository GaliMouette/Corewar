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
    char *str = "hello";
    char *charact = "ehlo";

    cr_assert_eq(my_strspn(str, charact), 5);
}

Test(my_strspn, char_Different)
{
    char *str = "hella";
    char *charact = "ehlo";

    cr_assert_eq(my_strspn(str, charact), 4);
}

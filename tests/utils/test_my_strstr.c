/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strstr.c
*/

#include "criterion/criterion.h"

char *my_strstr(char *haystack, char *needle);

Test(my_strstr, char_In_Str)
{
    char *str1 = "live:";
    char *charact = ":";

    cr_assert_str_eq(my_strstr(str1, charact), ":");
}

Test(my_strstr, char_Not_In_Str)
{
    char *str1 = "live :";
    char *charact = "p";

    cr_assert_null(my_strstr(str1, charact));
}

Test(my_strstr, str2_Empty)
{
    cr_assert_str_eq(my_strstr("li", "\0"), "li");
}

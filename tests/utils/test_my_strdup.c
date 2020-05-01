/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strdup.c
*/

#include "criterion/criterion.h"

char *my_strdup(char const *str);

Test(my_strdup, dup_Str)
{
    cr_assert_str_eq(my_strdup("Hello"), "Hello");
}

Test(my_strdup, str_Null)
{
    char *str = NULL;

    cr_assert_null(my_strdup(str));
}

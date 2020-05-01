/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strcmp.c
*/

#include <criterion/criterion.h>

int my_strcmp(char const *str1, char const *str2);

Test(my_strcmp, same_Str)
{
    cr_assert_eq(my_strcmp("Hello", "Hello"), 0);
}

Test(my_strcmp, str1_Big)
{
    cr_assert_eq(my_strcmp("HelloT", "Hello"), 84);
}

Test(my_strcmp, str2_Big)
{
    cr_assert_eq(my_strcmp("Hello", "HelloT"), -84);
}

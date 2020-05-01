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
    char *str1 = "Hello";
    char *str2 = "Hello";

    cr_assert_eq(my_strcmp(str1, str2), 0);
}

Test(my_strcmp, str1_Big)
{
    char *str1 = "HelloT";
    char *str2 = "Hello";

    cr_assert_eq(my_strcmp(str1, str2), 84);
}

Test(my_strcmp, str2_Big)
{
    char *str1 = "Hello";
    char *str2 = "HelloT";

    cr_assert_eq(my_strcmp(str1, str2), -84);
}

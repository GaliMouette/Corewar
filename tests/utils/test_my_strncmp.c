/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strcmp.c
*/

#include <criterion/criterion.h>

int my_strncmp(const char *str_1, const char *str_2, int n);

Test(my_strncmp, same_Strings)
{
    cr_assert_eq(my_strncmp("Hello", "Hello", 5), 0);
}

Test(my_strncmp, size_Higher_Than_Len_String)
{
    cr_assert_eq(my_strncmp("H", "H", 5), 0);
}

Test(my_strncmp, different_Strings)
{
    cr_assert_eq(my_strncmp("HelloT", "Hello", 6), 84);
}

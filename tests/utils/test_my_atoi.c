/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_atoi.c
*/

#include <criterion/criterion.h>

int my_atoi(char const *str);

Test(my_atoi, str_With_Number)
{
    cr_assert_eq(my_atoi("117"), 117);
}

Test(my_atoi, str_With__Negative_Number)
{
    cr_assert_eq(my_atoi("-117"), -117);
}

Test(my_atoi, str_With_letter)
{
    cr_assert_eq(my_atoi("abcd"), 0);
}

Test(my_atoi, str_With_Char_Below_Zero)
{
    cr_assert_eq(my_atoi("8.4"), 0);
}

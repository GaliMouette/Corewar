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
    char *str = "117";

    cr_assert_eq(my_atoi(str), 117);
}

Test(my_atoi, str_With__Negative_Number)
{
    char *str = "-117";

    cr_assert_eq(my_atoi(str), -117);
}
Test(my_atoi, str_With_letter)
{
    char *str = "abcd";

    cr_assert_eq(my_atoi(str), 0);
}

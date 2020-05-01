/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strnlen.c
*/

#include "criterion/criterion.h"

int my_strnlen(char const *str, int n);

Test(my_strnlen, definit_Len)
{
    char *str = "Pineapple";

    cr_assert_eq(my_strnlen(str, 6), 6);
}

Test(my_strnlen, str_Full)
{
    char *str = "Pineapple";

    cr_assert_eq(my_strnlen(str , 20), 9);
}

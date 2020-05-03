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
    cr_assert_eq(my_strnlen("Pineapple", 6), 6);
}

Test(my_strnlen, str_Full)
{
    cr_assert_eq(my_strnlen("Pineapple" , 20), 9);
}

/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strlen.c
*/

#include "criterion/criterion.h"

int my_strlen(char const *str);

Test(my_strlen, run)
{
    char *str = "Hello";

    cr_assert_eq(my_strlen(str), 5);
}

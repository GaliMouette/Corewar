/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strcspn.c
*/

#include "criterion/criterion.h"

int my_strcspn(char const *str, char const *chars);

Test(my_strcspn, char_Commun)
{
    cr_assert_eq(my_strcspn("live:", ":"), 4);
}

Test(my_strcspn, no_Char_Commun)
{
    cr_assert_eq(my_strcspn("Hello", "skirt"), 5);
}

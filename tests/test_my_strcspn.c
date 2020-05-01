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
    char *str1 = "live:";
    char *str2 = ":";

    cr_assert_eq(my_strcspn(str1, str2), 4);
}

Test(my_strcspn, no_Char_Commun)
{
    char *str1 = "Hello";
    char *str2 = "skirt";

    cr_assert_eq(my_strcspn(str1, str2), 5);
}

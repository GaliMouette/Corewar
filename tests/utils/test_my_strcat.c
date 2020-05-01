/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strcat.c
*/

#include "criterion/criterion.h"

int my_strlen(char const *str);

char *my_strcat(char const *str1, char const *str2);

Test(my_strcat, strcat_Run)
{
    char *str1 = "Bonjour";
    char *str2 = "Hello";

    cr_assert_str_eq(my_strcat(str1, str2), "BonjourHello");
}

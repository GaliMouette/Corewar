/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strlen.c
*/

#include <criterion/criterion.h>

int my_strlen(char const *str);

Test(my_strlen, run)
{
    cr_assert_eq(my_strlen("Hello"), 5);
}

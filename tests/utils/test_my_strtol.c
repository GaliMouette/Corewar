/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strtol.c
*/

#include "criterion/criterion.h"

long my_strtol(const char *str, int base);

Test(my_strtol, convert_Hexa_In_Decimal)
{
    cr_assert_eq(my_strtol("F", 16), 15);
}

Test(my_strtol, digit)
{
    cr_assert_eq(my_strtol("3457", 16), 13399);
}

Test(my_strtol, alpha)
{
    cr_assert_eq(my_strtol("FFFF", 16), 65535);
}

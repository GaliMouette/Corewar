/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_clean_line
*/

#include "asm/clean_line.h"
#include <criterion/criterion.h>

Test(clean_line, str_With_Tabulation)
{
    char str[] = "\tsalut";

    cr_assert_eq(clean_line(str), 0);
}

Test(clean_line, str_With_Quotes)
{
    char str[] = "o\"u\"i";

    cr_assert_eq(clean_line(str), 0);
}

Test(clean_line, str_With_Coma)
{
    char str[] = "s,alut";

    cr_assert_eq(clean_line(str), 0);
}

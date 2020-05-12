/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_clean_line
*/

#include "asm/clean_line.h"
#include <criterion/criterion.h>

Test(clean_line, str_With_Space)
{
    char str[] = "                  str        ";

    cr_assert_eq(clean_line(str), 0);
}

Test(clean_line, str_Begin_With_Backslash_n)
{
    char str[] = "\n           str            ";

    cr_assert_eq(clean_line(str), 1);
}

Test(clean_line, str_Begin_With_Comment)
{
    char str[] = "#                      ";

    cr_assert_eq(clean_line(str), 1);
}

Test(clean_line, str_Finish_With_Comment)
{
    char str[] = "ouidtrxtxt# ";

    cr_assert_eq(clean_line(str), 0);
}

Test(clean_line, str_Empty)
{
    char str[] = "";

    cr_assert_eq(clean_line(str), 1);
}

/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strtok_r.c
*/

#include "criterion/criterion.h"

char *my_strtok_r(char *str, const char *delim, char **backup);

char *my_strdup(char const *str);

int my_strspn(char const *str, char const *chars);

int my_strcspn(char const *str, char const *chars);

Test(my_strtok_r, run)
{
    char *backup;
    char *str = my_strdup("ac:av:an");
    char *delim = my_strdup(":");

    cr_assert_str_eq(my_strtok_r(str, delim, &backup), "ac");
}

Test(my_strtok_r, str_Null)
{
    char *backup = my_strdup("av:an");
    char *str = NULL;
    char *delim = my_strdup(":");

    cr_assert_str_eq(my_strtok_r(str, delim, &backup), "av");
}

Test(my_strtok_r, end_Str)
{
    char *backup = my_strdup("av:an");
    char *str =  my_strdup("\0");
    char *delim = my_strdup(":");

    cr_assert_null(my_strtok_r(str, delim, &backup));
}

Test(my_strtok_r, no_Delim_In_Str)
{
    char *backup;
    char *str =  my_strdup("av");
    char *delim = my_strdup(":");

    cr_assert_str_eq(my_strtok_r(str, delim, &backup), "av");
}

Test(my_strtok_r, delim)
{
    char *backup;
    char *str =  my_strdup("::");
    char *delim = my_strdup(":");

    cr_assert_null(my_strtok_r(str, delim, &backup));
}

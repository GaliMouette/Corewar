/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_memcpy.c
*/

#include <criterion/criterion.h>

void *my_memcpy(void *dest, const void *src, int n);

Test(my_memcpy, str_Copy)
{
    char str1[6] = "Hello";
    char *str2 = "Maybe";

    cr_assert_str_eq(my_memcpy(str1, str2, 5), str2);
}

Test(my_memcpy, str_copy_Str2_Null)
{
    char str1[6] = "Hello";
    char *str2 = NULL;

    cr_assert_str_eq(my_memcpy(str1, str2, 20), str1);
}

Test(my_memcpy, str_copy_Str1_Null)
{
    char *str1 = NULL;
    char *str2 = "Hello";

    cr_assert_null(my_memcpy(str1, str2, 20));
}

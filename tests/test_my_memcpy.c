/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_memcpy.c
*/

#include <criterion/criterion.h>

void *my_memcpy(void *dest, const void *src, int n);

Test(my_memcpy, str_copy)
{
    char str1[6] = "Hello";
    char *str2 = "Maybe";

    cr_assert_str_eq(my_memcpy(str1, str2, 5), str2);
}

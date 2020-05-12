/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** test_my_strndup.c
*/

#include <criterion/criterion.h>

int my_strnlen(char const *str, int n);

void *my_memcpy(void *dest, const void *src, int n);

char *my_strndup(const char *s, int n);

Test(my_strndup, half_Word)
{
    cr_assert_str_eq(my_strndup("Live", 2), "Li");
}

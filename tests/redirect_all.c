/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** redirect_all
*/

#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

void redirect_all_stderr(void)
{
    cr_redirect_stderr();
}

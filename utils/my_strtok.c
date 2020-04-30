/*
** EPITECH PROJECT, 2020
** PSU_corewar_2019
** File description:
** my_strtok
*/

#include "utils.h"

char *my_strtok(char *str, const char *delim)
{
    static char *backup;

    return my_strtok_r(str, delim, &backup);
}

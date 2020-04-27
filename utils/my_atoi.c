/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_atoi
*/

#include "utils.h"

int my_atoi(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i]; ++i) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        res = res * 10 + str[i] - '0';
    }
    return sign*res;
}

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#include "asm.h"
#include "utils.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (2 == argc && !my_strcmp("-h", argv[1])) {
        write(1, USAGE, 148);
    }
    return 0;
}

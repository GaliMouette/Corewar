/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_prog_overlap
*/

#include "corewar/init/adresses/check_prog_overlap.h"

int check_prog_overlap(init_t *init, arena_t *arena)
{
    int s1, s2, e1, e2;

    for (int i = 0; i < 4; i++) {
        if (!(init->champs[i].path)) {
            continue;
        }
        s1 = init->champs[i].load_address % MEM_SIZE;
        e1 = s1 + init->champs[i].header.prog_size % MEM_SIZE;
        for (int j = i + 1; j < 4; j++) {
            if (!(init->champs[j].path)) {
                continue;
            }
            s2 = init->champs[j].load_address % MEM_SIZE;
            e2 = s2 + init->champs[j].header.prog_size % MEM_SIZE;
            if ((s1 <= s2 && s2 <= e1) || (s2 <= e1 && e1 <= e2)) {
                write(2, "Program overlap detected.\n", 26);
                return 1;
            }
        }
    }
    return 0;
}

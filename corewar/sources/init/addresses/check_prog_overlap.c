/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_prog_overlap
*/

#include "corewar/init/adresses/check_prog_overlap.h"

int check_prog_overlap(init_t *init, arena_t *arena)
{
    for (int i = 0; i < arena->nb_players; i++) {
        for (int j = i + 1; j < arena->nb_players; j++) {
            if ((((init->champs[i].load_address
            + init->champs[i].header.prog_size) % MEM_SIZE)
            > (init->champs[j].load_address % MEM_SIZE) + 1)
            && (((init->champs[i].load_address
            + init->champs[i].header.prog_size) % MEM_SIZE)
            < ((init->champs[j].load_address
            + init->champs[j].header.prog_size) % MEM_SIZE) + 1)) {
                write(2, "Program overlap detected.\n", 26);
                return 1;
            }
        }
    }
    return 0;
}

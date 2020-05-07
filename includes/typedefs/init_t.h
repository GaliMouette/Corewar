/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** init_t
*/

#ifndef INIT_T_H_
#define INIT_T_H_

#include "typedefs/header_t.h"

struct champ_init_s {
    int number;
    int load_address;
    char *path;
    header_t header;
};

struct init_s {
    long dump;
    struct champ_init_s champs[4];
};

typedef struct init_s init_t;

#endif /* !INIT_T_H_ */

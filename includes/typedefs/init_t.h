/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** init_t
*/

#ifndef INIT_T_H_
#define INIT_T_H_

#include "typedefs/header_t.h"

struct __attribute__((packed)) champ_init_s {
    int file_desc;
    int number;
    int load_address;
    char *path;
    header_t header;
};

struct init_s {
    long dump;
    struct champ_init_s champs[4];
};

#define CHAMP_INIT {-1, -1, -1, 0, {0}}
#define INIT {-1, {CHAMP_INIT, CHAMP_INIT, CHAMP_INIT, CHAMP_INIT}}

typedef struct init_s init_t;

#endif /* !INIT_T_H_ */

/*
2j = 0 , 6144/2 //TODO
2j = x , 6144/2 + X //TODO
2j = x, y //TODO
3j = 0, 6144/3, 2*(6144/3) //TODO
3j = x, 6144/3 + x, 2*(6144/3) + x //TODO
3j = x, y, (y - x) = a (6144 - y + x)= b si a > b : x + (6144 - x + y - 6144)/2 si b > a : y + (6144 - y + x)/2 //TODO
3j = x, y, z //TODO
4j = 0, 6144/4, 2*(6144/4), 3*(6144/4)//TODO
4j = x, 6144/4 + x, 2*(6144/4) + x, 3*(6144/4) + x //TODO
4j = x, y , x + (y - x)/2 | y + (6144 - y + x)/2, x + (y - x)/2 | y + (z - y)/2 | z + (6144 - z + x)/2
4j = x, y, z, x + (6144 - x + y - 6144)/2 | y + (6144 - y + z - 6144)/2 | z + (6144 - z + x)/2
4j = x, y, z, w //TODO
*/

/*  int nb_player;
    int nb_renseigné; -> for nb_player if(!=-1) : + 1
    int x = 0;
    int y = 0;
    int z = 0;

    if (nb_renseigné == nb_player)
        return 0;
    if nb_renseigné < 2
        for (int i = 0; i != nb_player; i++)
            if (player[i].load_adress != -1)
                x = load_adress;
        for (int i = 0, j = 0; i != nb_player; i++)
            if (player[i].load_adress == - 1)
                j++;
                load_adress = j * (MEMSIZE/nb_player) + x;
    else





Appliqué modulo %6144
*/

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** champion_t
*/

#ifndef CHAMPION_T_H_
#define CHAMPION_T_H_

#define MAX_PROG_NAME_LEN       128

struct champion_s {
    char name[MAX_PROG_NAME_LEN];
    int number;
    int load_address;
};

struct champions_s {
    struct champion_s champs[4];
};

typedef struct champions_s champions_t;

//TODO Add redcode structure in champion_s

#endif /* !CHAMPION_T_H_ */

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** arena_t
*/

#ifndef ARENA_T_H_
#define ARENA_T_H_

#define MEM_SIZE        (6 * 1024)
#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40
#define IDX_MOD         512

#define REG_NUMBER      16

#define IND_SIZE        2
#define DIR_SIZE        4
#define REG_SIZE        DIR_SIZE

enum status_e
{
    DEAD,
    ALIVE,
    WIN
};

struct executable_s
{
    int pc;
    int carry;
    int registry[REG_NUMBER];
};

struct player_s
{
    int number;
    enum status_e status;
    char *name;
};

struct __attribute__((packed)) arena_s
{
    char memory[MEM_SIZE];
    int calls_to_live;
    unsigned int current_cycle;
    int cycle_to_die;
    struct player_s players[4];
    struct executable_s **execs;
};

typedef struct arena_s arena_t;

#define ARENA {{0}, 0, 0, CYCLE_TO_DIE, {0}, NULL}

#endif /* !ARENA_T_H_ */

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
    WIN,
};

enum arg_type_e
{
    NONE,
    REG_TYPE,
    DIR_TYPE,
    IND_TYPE,
};

struct loaded_op_s
{
    int is_op_loaded;
    int opcode;
    enum arg_type_e args_type[4];
    int args_size[4];
    int args[4];
    int pc_offset;
    int wait_cycle;
};

typedef struct loaded_op_s loaded_op_t;

struct executable_s
{
    int player;
    int pc;
    int carry;
    int registry[REG_NUMBER];
    struct loaded_op_s loaded_op;
};

struct player_s
{
    int number;
    enum status_e status;
    char *name;
};

struct arena_s
{
    char memory[MEM_SIZE];
    int nb_players;
    int calls_to_live;
    unsigned int current_cycle;
    unsigned int cycle_to_die;
    struct player_s players[4];
    struct executable_s **execs;
};

typedef struct arena_s arena_t;

#define ARENA {{0}, 0, 0, 0, CYCLE_TO_DIE, {0}, NULL}

#endif /* !ARENA_T_H_ */

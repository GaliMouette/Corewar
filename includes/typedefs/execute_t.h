/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** execute_t
*/

#ifndef EXECUTE_T_H_
#define EXECUTE_T_H_

struct execute_s
{
    int opcode;
    int args_type[4];
    int args[4];
    int pc_offset;
};

typedef struct execute_s execute_t;

#endif /* !EXECUTE_T_H_ */

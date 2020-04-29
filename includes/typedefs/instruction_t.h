/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** instruction
*/

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

struct instruction_s
{
    struct  instruction_s *prev;
    struct  instruction_s *next;
    char    *label;
    char    opcode;
    char    args_types;
    char    registers[3];
    short   indirect[3];
    int     direct[3];
    char    labels[3];
    int     pc;
};

typedef struct instruction_s instruction_t;

#endif /* !INSTRUCTION_H_ */

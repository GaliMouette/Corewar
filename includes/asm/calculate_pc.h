/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** calculate_pc
*/

#ifndef CALCULATE_PC_H_
#define CALCULATE_PC_H_

#include "typedefs/instruction_t.h"

long calculate_pc(instruction_t *head);
static int get_special_op_len(instruction_t *head);
static int get_op_len(instruction_t *head);

#endif /* !CALCULATE_PC_H_ */

/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** op
*/

#ifndef OP_H_
#define OP_H_

#include "typedefs/op_t.h"

#define T_REG   1   //  Registry type   (rX)
#define T_DIR   2   //  Direct type     (%value)
#define T_IND   4   //  Indirect type   (value)

extern op_t op_tab[];

#endif /* !OP_H_ */

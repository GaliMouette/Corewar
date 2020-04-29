/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** op_t
*/

#ifndef OP_T_H_
#define OP_T_H_

#define MAX_ARGS_NUMBER         4           //! DO NOT CHANGE (2 ^ IND_SIZE)

typedef char args_type_t;

struct __attribute__((packed)) op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
};

typedef struct op_s op_t;

#endif /* !OP_T_H_ */

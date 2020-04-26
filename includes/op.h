/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** op
*/

#ifndef OP_H_
#define OP_H_

#define MEM_SIZE                (6 * 1024)
#define IDX_MOD                 512         //  Index modulo
#define MAX_ARGS_NUMBER         4           //! DO NOT CHANGE (2 ^ MOD_SIZE)

//  Reserved characters
#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','

//  Authorized label characters
#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

//  Header
#define NAME_CMD_STRING         ".name"
#define PROG_NAME_LENGTH        128
#define COMMENT_CMD_STRING      ".comment"
#define COMMENT_LENGTH          2048

//  Sizes (in bytes)
#define IND_SIZE        2           //  Short int (-32768 to 32767)
#define DIR_SIZE        4           //  Int       (-2147483648 to 2147483647)
#define REG_SIZE        DIR_SIZE

//  Registres
#define REG_NUMBER              16  //  Number of registres

//  Arguments types
#define T_REG                   1   //  Registry type    (rX)
#define T_DIR                   2   //  Direct type      (%value)
#define T_IND                   4   //  Indirect type    (value)
#define T_LAB                   8   //  Label type       (value:)

//  Live and cycles
#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40

//  Magic
#define COREWAR_EXEC_MAGIC      0xea83f3    //! DO NOT TOUCH

typedef char args_type_t;

struct op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
};

typedef struct op_s op_t;

extern op_t op_tab[];

struct header_s
{
   int  magic;
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
};

typedef struct header_s header_t;

#endif /* !OP_H_ */

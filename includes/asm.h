/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#define USAGE \
"USAGE\
\n./asm file_name[.s]\
\nDESCRIPTION\
\nfile_name file in assembly language to be converted into file_name.cor, an\
\nexecutable in the Virtual Machine.\
\n"

#include "op.h"

int compile_file(char const *path);
int clean_line(char *line);
int get_header(char *line, header_t *header, int is_set);
int get_name(char *args, header_t *header, int is_set);

#endif /* !ASM_H_ */

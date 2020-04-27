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

#include <stdio.h>

int compile_file(char const *path);
FILE *open_file(char const *path);

//  Cleaning line
int clean_line(char *line);
void remove_tabulations(char *line);
void remove_spaces(char *line);

#endif /* !ASM_H_ */

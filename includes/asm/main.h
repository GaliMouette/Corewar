/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "utils.h"
#include <unistd.h>

#define USAGE \
"USAGE\
\n./asm file_name[.s]\
\nDESCRIPTION\
\nfile_name file in assembly language to be converted into file_name.cor, an\
\nexecutable in the Virtual Machine.\
\n"

//  Using
int compile_file(char const *path);

#endif /* !MAIN_H_ */

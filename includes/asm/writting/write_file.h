/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** write_file
*/

#ifndef WRITE_FILE_H_
#define WRITE_FILE_H_

#include "typedefs/header_t.h"
#include "typedefs/instruction_t.h"
#include "utils.h"
#include <fcntl.h>

int write_file(char const *path, header_t *header, instruction_t *head);
static int open_file(char const *path);

//  Using
void write_header(header_t *header, int fd);
void write_instructions(instruction_t *head, int fd);

#endif /* !WRITE_FILE_H_ */

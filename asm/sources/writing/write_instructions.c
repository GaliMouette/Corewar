/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** write_instruction
*/

#include "asm/writting/write_instructions.h"

int write_instructions(instruction_t *head, int fd)
{
    while (head) {
        write(fd, &head->opcode, 1);
        if (2 == write_special(head, fd)) {
        } else if (2 == write_short(head, fd)) {
        } else {
            write_simple(head, fd);
        }
        head = head->next;
    }
    return 0;
}

static int write_special(instruction_t *head, int fd)
{
    char opcode = head->opcode;

    if (0x01 == opcode) {
        reverse_write(fd, &head->direct[0], 4);
    } else if (0x09 == opcode || 0x0C == opcode || 0x0F== opcode) {
        reverse_write(fd, &head->direct[0], 2);
    } else {
        return 0;
    }
    return 2;
}

static int write_short(instruction_t *head, int fd)
{
    char opcode = head->opcode;

    write(fd, &head->args_types, 1);
    if (0x0A == opcode || 0x0B == opcode || 0x0E == opcode) {
        for (int i = 3; i; i--) {
            switch ((head->args_types >> (i * 2) & 3)) {
            case 1:
                write(fd, &head->registers[3 - i], 1);
                break;
            case 2:
                reverse_write(fd, &head->direct[3 - i], 2);
                break;
            case 3:
                reverse_write(fd, &head->indirect[3 - i], 2);
                break;
            }
        }
    } else {
        return 0;
    }
    return 2;
}

static int write_simple(instruction_t *head, int fd)
{
    for (int i = 3; i; i--) {
        switch ((head->args_types >> (i * 2) & 3)) {
        case 1:
            write(fd, &head->registers[3 - i], 1);
            break;
        case 2:
            reverse_write(fd, &head->direct[3 - i], 4);
            break;
        case 3:
            reverse_write(fd, &head->indirect[3 - i], 2);
            break;
        }
    }
    return 0;
}

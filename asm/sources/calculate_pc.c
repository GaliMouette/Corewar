/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** calculate_pc
*/

#include "asm/calculate_pc.h"

long calculate_pc(instruction_t *head)
{
    int new_pc = 0;

    head->pc = new_pc;
    while (head->next) {
        new_pc += get_special_op_len(head) ?: get_op_len(head);
        head->next->pc = new_pc;
        head = head->next;
    }
    new_pc += get_special_op_len(head) ?: get_op_len(head);
    return new_pc;
}

static int get_special_op_len(instruction_t *head)
{
    char opcode = head->opcode;

    if (0x01 == opcode) {
        return 5;
    } else if (0x09 == opcode || 0x0C == opcode || 0x0F == opcode) {
        return 3;
    } else {
        return 0;
    }
}

static int get_op_len(instruction_t *head)
{
    char opcode = head->opcode;
    int op_len = 2;

    if (0x0A == opcode || 0x0B == opcode || 0x0E == opcode) {
        for (int i = 0; i < 4; i++) {
            if (head->args_types >> (i * 2) & 3) {
                op_len += (1 == (head->args_types >> (i * 2) & 3)) ? 1 : 2;
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            op_len += (1 == (head->args_types >> (i * 2) & 3)) ? 1 : 0;
            op_len += (2 == (head->args_types >> (i * 2) & 3)) ? 4 : 0;
            op_len += (3 == (head->args_types >> (i * 2) & 3)) ? 2 : 0;
        }
    }
    return op_len;
}

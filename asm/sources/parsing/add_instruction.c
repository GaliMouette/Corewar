/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** add_instruction
*/

#include "asm/parsing/add_instruction.h"

int add_instruction
(char *args[6], instruction_t **head, int info[2], labels_t *saved_labels)
{
    instruction_t *new = malloc(sizeof(instruction_t));
    instruction_t *dummy = *head;

    if (!new) {
        return 1;
    }
    if (set_instruction(args, info, saved_labels, new)) {
        return 1;
    }
    new->next = NULL;
    if (!dummy) {
        new->prev = NULL;
        *head = new;
    } else {
        while (dummy->next) {
            dummy = dummy->next;
        }
        new->prev = dummy;
        dummy->next = new;
    }
    return 0;
}

static int set_instruction
(char *args[6], int info[2], labels_t *saved_labels, instruction_t *new)
{
    int index = saved_labels->nb_labels - 1;

    if (info[1]) {
        new->label = my_strdup(saved_labels->labels[index]);
        if (!new->label) {
            free(new);
            return 1;
        }
    }
    new->opcode = (char) info[0];
    new->args_types = (unsigned char) get_args_types(args);
    set_args(args, new);
    new->pc = 0;
    return 0;
}

static int set_args(char *args[6], instruction_t *new)
{
    int i = 3;

    while (i) {
        switch (new->args_types >> (i * 2) & 3) {
        case 1:
            new->registers[3 - i] = (char) my_atoi(args[4 - i]);
            break;
        case 2:
            if (set_direct_or_indirect(args, new, i, 1)) {
                return 1;
            }
            break;
        case 3:
            if (set_direct_or_indirect(args, new, i, 0)) {
                return 1;
            }
            break;
        }
        i--;
    }
    return 0;
}

static int set_direct_or_indirect
(char *args[6], instruction_t *new, int i, int direct)
{
    int label = set_label(args, new, i, direct);

    if (1 == label) {
        return 1;
    } else if (2 == label) {
        return 0;
    } else {
        new->direct[3 - i] = my_atoi(args[4 - i]);
        return 0;
    }
}

static int set_label(char *args[6], instruction_t *new, int i, int direct)
{
    if (':' == args[4 - i][direct]) {
        new->labels[3 - i] = my_strdup(args[4 - i] + 1 + direct);
        if (!new->labels[3 - i]) {
            return 1;
        }
        return 2;
    }
    return 0;
}

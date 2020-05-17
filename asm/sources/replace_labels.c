/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** replace_labels
*/

#include "asm/replace_labels.h"

int replace_labels(instruction_t *head, long prog_size)
{
    instruction_t *dummy = head;

    while (head) {
        if (head->labels[0] && set_pc(head, dummy, (int [2]){0, 6}, prog_size)){
            return 1;
        }
        if (head->labels[1] && set_pc(head, dummy, (int [2]){1, 4}, prog_size)){
            return 1;
        }
        if (head->labels[2] && set_pc(head, dummy, (int [2]){2, 2}, prog_size)){
            return 1;
        }
        head = head->next;
    }
    last_label(NULL, 1);
    return 0;
}

static int set_pc(instruction_t *head,
instruction_t *dummy, int info[2], long prog_size)
{
    int pc = head->pc;
    unsigned char args_types = head->args_types;
    int label_pc = get_label_pc(dummy, head->labels[info[0]], prog_size);

    if (-1 == label_pc) {
        return 1;
    }
    switch ((args_types >> info[1]) & 3) {
    case 2:
        head->direct[info[0]] = label_pc - pc;
        break;
    case 3:
        head->indirect[info[0]] = (short) (label_pc - pc);
        break;
    }
    return 0;
}

static int get_label_pc(instruction_t *dummy, char *label, long prog_size)
{
    int pc = -1;

    while (-1 == pc && dummy) {
        if (!dummy->label) {
            dummy = dummy->next;
            continue;
        }
        if (!my_strcmp(dummy->label, label)) {
            pc = dummy->pc;
        }
        dummy = dummy->next;
    }
    if (-1 == pc) {
        if (get_label_space(last_label(NULL, 0), label)) {
            pc = (int) prog_size;
        } else
            write(2, "Reference to undefined label.\n", 30);
    }
    return pc;
}

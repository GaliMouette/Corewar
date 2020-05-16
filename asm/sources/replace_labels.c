/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** replace_labels
*/

#include "asm/replace_labels.h"

int replace_labels(instruction_t *head)
{
    instruction_t *dummy = head;

    while (head) {
        if (head->labels[0] && set_pc(head, dummy, 0, 6)) {
            return 1;
        }
        if (head->labels[1] && set_pc(head, dummy, 1, 4)) {
            return 1;
        }
        if (head->labels[2] && set_pc(head, dummy, 2, 2)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

static int set_pc(instruction_t *head,
instruction_t *dummy, int index, int shift)
{
    int pc = head->pc;
    unsigned char args_types = head->args_types;
    int label_pc = get_label_pc(dummy, head->labels[index]);

    if (-1 == label_pc) {
        return 1;
    }
    switch ((args_types >> shift) & 3) {
    case 2:
        head->direct[index] = label_pc - pc;
        break;
    case 3:
        head->indirect[index] = (short) (label_pc - pc);
        break;
    }
    return 0;
}

static int get_label_pc(instruction_t *dummy, char *label)
{
    int pc = -1;

    while (-1 == pc && dummy) {
        if (!dummy->label) {
            dummy = dummy->next;
            continue;
        }
        if ((my_strstr(dummy->label, " ")
        && get_label_space(dummy->label, label))
        || !my_strcmp(dummy->label, label)) {
            pc = dummy->pc;
        }
        dummy = dummy->next;
    }
    if (-1 == pc) {
        write(2, "Reference to undefined label.\n", 30);
    }
    return pc;
}

static int get_label_space(char *dummy, char *label)
{
    int label_len;
    int dummy_len;

    while (*dummy) {
        dummy += (' ' == dummy[0]);
        dummy_len = my_strcspn(dummy, " ");
        label_len = my_strlen(label);
        if (label_len == dummy_len && !my_strncmp(dummy, label, label_len)){
            return 1;
        }
        dummy += my_strcspn(dummy, " ");
    }
    return 0;
}

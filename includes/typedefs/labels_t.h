/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** labels_t
*/

#ifndef LABELS_T_H_
#define LABELS_T_H_

struct __attribute__((packed)) labels_s
{
    char **labels;
    int nb_labels;
};

typedef struct labels_s labels_t;

#endif /* !LABELS_T_H_ */

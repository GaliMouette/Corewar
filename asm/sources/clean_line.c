/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** clean_line
*/

#include "asm.h"
#include "utils.h"

int clean_line(char *line)
{
    if ('\n' == line[0]) {
        return 1;
    }
    my_strtok(line, "\n");
    if (my_strstr(line, "#")) {
        if (line == my_strstr(line, "#")) {
            return 1;
        }
        my_strstr(line, "#")[0] = '\0';
    }
    remove_tabulations(line);
    remove_spaces(line);
    if (!line[0]) {
        return 1;
    }
    return 0;
}

void remove_tabulations(char *line)
{
    int i = 0;

    while (line[i]) {
        if ('\t' == line[i]) {
            line[i] = ' ';
        }
        i++;
    }
}

void remove_spaces(char *line)
{
    int i = 0;
    int j = 0;

    while (' ' == line[j]) {
        j++;
    }
    while (line[j]) {
        if (' ' == line[j] && ' ' == line[j + 1]) {
            j++;
            continue;
        }
        line[i] = line[j];
        i++;
        j++;
    }
    line[i] = '\0';
}

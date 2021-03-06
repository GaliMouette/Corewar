/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** clean_line
*/

#include "asm/clean_line.h"

int clean_line(char *line)
{
    if ('\n' == line[0]) {
        return 1;
    }
    my_strtok(line, "\n");
    if (remove_comment(line)) {
        return 1;
    }
    remove_tabulations(line);
    remove_comas(line);
    remove_spaces(line);
    if (!line[0]) {
        return 1;
    }
    return 0;
}

static int remove_comment(char *line)
{
    int i = 0;
    int quotes = 0;

    if (COMMENT_CHAR == line[0]) {
        return 1;
    }
    while (line[i]) {
        if ('\"' == line[i] && !quotes) {
            quotes = 1;
        } else if ('\"' == line[i] && quotes) {
            quotes = 0;
        }
        if (!quotes && '#' == line[i]) {
            line[i] = '\0';
            break;
        }
        i++;
    }
    return 0;
}

static void remove_tabulations(char *line)
{
    int i = 0;
    int quotes = 0;

    while (line[i]) {
        if ('\"' == line[i] && !quotes) {
            quotes = 1;
        } else if ('\"' == line[i] && quotes) {
            quotes = 0;
        }
        if (!quotes && '\t' == line[i]) {
            line[i] = ' ';
        }
        i++;
    }
}

static void remove_comas(char *line)
{
    int i = 0;
    int quotes = 0;

    while (line[i]) {
        if ('\"' == line[i] && !quotes) {
            quotes = 1;
        } else if ('\"' == line[i] && quotes) {
            quotes = 0;
        }
        if (!quotes && ',' == line[i]) {
            line[i] = ' ';
        }
        i++;
    }
}

static void remove_spaces(char *line)
{
    int i = 0;
    int j = 0;
    int quotes = 0;

    while (' ' == line[j]) {
        j++;
    }
    while (line[j]) {
        if ('\"' == line[i] && !quotes) {
            quotes = 1;
        } else if ('\"' == line[i] && quotes) {
            quotes = 0;
        }
        if (!quotes && ' ' == line[j] && (' ' == line[j + 1] || !line[j + 1])) {
            j++;
            continue;
        }
        line[i++] = line[j++];
    }
    line[i] = '\0';
}

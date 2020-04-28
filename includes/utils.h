/*
** EPITECH PROJECT, 2020
** PSU_corewar_2019
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

int is_printable(char const *str);
int is_digit(char const *str);
int my_atoi(char const *str);
char *my_strstr(char *haystack, char *needle);
int my_strlen(char const *str);
char *my_strcat(char const *str1, char const *str2);
int my_strcspn(char const *str, char const *chars);
int my_strspn(char const *str, char const *chars);
char *my_strtok(char *str, const char *delim);
char *my_strtok_r(char *str, const char *delim, char **backup);
int my_strcmp(char const *str1, char const *str2);
void my_put_nbr(int number);
char *my_strdup(char const *str);
void *my_memmove(void *dest, const void *src, int n);
void *my_memcpy(void *dest, const void *src, int n);

#endif /* !UTILS_H_ */

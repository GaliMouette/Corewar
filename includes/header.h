/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
** File description:
** header
*/

#ifndef HEADER_H_
#define HEADER_H_

//  Magic
#define MAGIC      0xea83f3    //! DO NOT TOUCH


#define NAME_CMD_STR            ".name"
#define COMMENT_CMD_STR         ".comment"
#define MAX_PROG_NAME_LEN       128
#define MAX_COMMENT_LEN         2048

struct __attribute__((packed)) header_s
{
    int  magic;
    char prog_name[MAX_PROG_NAME_LEN + 1];
    long  prog_size;
    char comment[MAX_COMMENT_LEN + 1];
    int padding;
};

typedef struct header_s header_t;

int get_header(char *line, header_t *header, int is_set);
int get_name(char *args, header_t *header, int is_set);
int get_comment(char *args, header_t *header, int is_set);

#endif /* !HEADER_H_ */

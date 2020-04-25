##
## EPITECH PROJECT, 2020
## CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
## File description:
## Makefile
##

NAME	=

CC	=	gcc

RM	=	rm	-f

SRCS	=

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I
CFLAGS	+=	-Wall	-Wextra

LDFLAGS	=

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC)	$(OBJS)	-o	$(NAME)	$(LDFLAGS)

clean:
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re

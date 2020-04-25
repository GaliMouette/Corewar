##
## EPITECH PROJECT, 2020
## CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
## File description:
## Makefile
##

CC	=	clang

RM	=	rm	-f

ASM_OBJS		=	$(patsubst	%.c,	%.o,	$(shell	find	asm/sources/		-type	f	-name	"*.c"))
COREWAR_OBJS	=	$(patsubst	%.c,	%.o,	$(shell	find	corewar/sources/	-type	f	-name	"*.c"))

CFLAGS	=	-I	includes
CFLAGS	+=	-Weverything
CFLAGS	+=	-g3

LDFLAGS	=

all:	$(ASM_OBJS)	$(COREWAR_OBJS)
	$(CC)	$(ASM_OBJS)		-o	asm/asm			$(LDFLAGS)
	$(CC)	$(COREWAR_OBJS)	-o	corewar/corewar	$(LDFLAGS)

clean:
	$(RM)	$(ASM_OBJS)
	$(RM)	$(COREWAR_OBJS)

fclean:	clean
	$(RM)	asm/asm
	$(RM)	corewar/corewar

re:	fclean	all

.PHONY:	all	clean	fclean	re

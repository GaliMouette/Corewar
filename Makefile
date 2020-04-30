##
## EPITECH PROJECT, 2020
## CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
## File description:
## Makefile
##

CC	=	clang

RM	=	rm	-f

ASM_NAME		=	./asm/asm
COREWAR_NAME	=	./corewar/corewar
TESTS_NAME		=	./unit_tests

ASM_SRCS		=	$(shell	find	./asm/sources/		-type	f	-name	"*.c")
COREWAR_SRCS	=	$(shell	find	./corewar/sources/	-type	f	-name	"*.c")
UTILS_SRCS		=	$(shell	find	./utils/			-type	f	-name	"*.c")

ASM_OBJS		=	$(patsubst	%.c,	%.o,	$(ASM_SRCS))
COREWAR_OBJS	=	$(patsubst	%.c,	%.o,	$(COREWAR_SRCS))
UTILS_OBJS		=	$(patsubst	%.c,	%.o,	$(UTILS_SRCS))

INCLUDES	=	$(shell	find	includes/	-type	f	-name	"*.h")


TESTS_SRCS	=	tests/test_my_strcmp.c	\
				utils/my_strcmp.c		\
				tests/test_is_digit.c	\
				utils/is_digit.c		\
				tests/test_is_printable.c	\
				utils/is_printable.c		\
				tests/test_my_atoi.c		\
				utils/my_atoi.c				\
				tests/test_my_memcpy.c		\
				utils/my_memcpy.c			\
				tests/test_my_put_nbr.c		\
				utils/my_put_nbr.c			\

TESTS_OBJS	=	$(patsubst	%.c,	%.o,	$(TESTS_SRCS))

CFLAGS	=	-I	./includes/
CFLAGS	+=	-g3
ifneq	($(MAKECMDGOALS),	tests_run)
	CFLAGS	+=	-Weverything
endif

LDFLAGS	=

ifeq	($(MAKECMDGOALS),	tests_run)
	CC		=	gcc
	CFLAGS	+=	--coverage
	LDFLAGS	+=	-lcriterion
endif

all:	$(ASM_OBJS)	$(COREWAR_OBJS)	$(UTILS_OBJS)
	$(CC)	$(ASM_OBJS)		$(UTILS_OBJS)	-o	$(ASM_NAME)		$(LDFLAGS)
	$(CC)	$(COREWAR_OBJS)	$(UTILS_OBJS)	-o	$(COREWAR_NAME)	$(LDFLAGS)


$(ASM_OBJS):		$(INCLUDES)
$(COREWAR_OBJS):	$(INCLUDES)
$(UTILS_OBJS):		$(INCLUDES)

tests_run:	$(TESTS_OBJS)
	$(CC)	$(TESTS_OBJS)	-o	$(TESTS_NAME)	$(LDFLAGS)	$(CFLAGS)
	$(TESTS_NAME)

tests_clean:
	$(RM)	$(shell	find	-type	f	-name	"*.gc*")

clean:	tests_clean
	$(RM)	$(shell	find	-type	f	-name	"*.o")

fclean:	clean
	$(RM)	$(ASM_NAME)
	$(RM)	$(COREWAR_NAME)
	$(RM)	$(TESTS_NAME)

re:	fclean	all

.PHONY:	all	tests_run	tests_clean	clean	fclean	re

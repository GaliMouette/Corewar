##
## EPITECH PROJECT, 2020
## CPE_corewar_2019 [Container epitech_image (/CPE_corewar_2…]
## File description:
## Makefile
##

CC	=
ifeq	($(MAKECMDGOALS),	tests_run)
	CC	+=	gcc
else
	CC	+=	clang
endif

CFLAGS	=	-I	./includes/
CFLAGS	+=	-g3
ifeq	($(MAKECMDGOALS),	tests_run)
	CFLAGS	+=	--coverage
else
	CFLAGS	+=	-Weverything
endif

LDFLAGS	=
ifeq	($(MAKECMDGOALS),	tests_run)
	LDFLAGS	+=	-lcriterion
endif

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

INCLUDES	=	$(shell	find	./includes/	-type	f	-name	"*.h")

TESTS_SRCS	=	tests/utils/test_is_digit.c		\
				utils/is_digit.c				\
				tests/utils/test_is_printable.c	\
				utils/is_printable.c			\
				tests/utils/test_my_atoi.c		\
				utils/my_atoi.c					\
				tests/utils/test_my_memcpy.c	\
				utils/my_memcpy.c				\
				tests/utils/test_my_put_nbr.c	\
				utils/my_put_nbr.c				\
				tests/utils/test_my_strcat.c	\
				utils/my_strcat.c				\
				tests/utils/test_my_strcmp.c	\
				utils/my_strcmp.c				\
				tests/utils/test_my_strcspn.c	\
				utils/my_strcspn.c				\
				tests/utils/test_my_strdup.c	\
				utils/my_strdup.c				\
				tests/utils/test_my_strlen.c	\
				utils/my_strlen.c				\
				tests/utils/test_my_strndup.c	\
				utils/my_strndup.c				\
				tests/utils/test_my_strnlen.c	\
				utils/my_strnlen.c				\
				tests/utils/test_my_strspn.c	\
				utils/my_strspn.c				\
				tests/utils/test_my_strstr.c	\
				utils/my_strstr.c				\
				tests/utils/test_my_strtok_r.c	\
				utils/my_strtok_r.c				\
				tests/redirect_all_stdout.c

TESTS_OBJS	=	$(patsubst	%.c,	%.o,	$(TESTS_SRCS))

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
	$(RM)	$(shell	find	./	-type	f	-name	"*.gc*")

clean:	tests_clean
	$(RM)	$(shell	find	./	-type	f	-name	"*.o")

fclean:	clean
	$(RM)	$(ASM_NAME)
	$(RM)	$(COREWAR_NAME)
	$(RM)	$(TESTS_NAME)

re:	fclean	all

.PHONY:	all	tests_run	tests_clean	clean	fclean	re

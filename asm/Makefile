##
## Makefile for Corewar in /home/odet_a/work/Corewar/asm
##
## Made by
## Login   <odet_a@epitech.net>
##
## Started on  Thu Feb 27 18:18:06 2014
## Last update Tue Mar  4 16:58:16 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -ggdb3 -g3

NAME=		asm

SRCS=		main.c \
		op.c \
		parsing.c \
		basic.c \
		xfunction.c \
		get_next_line.c \
		recup.c \
		fill_header.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re

##
## Makefile for Corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue Feb 25 18:54:15 2014 romaric
## Last update Wed Feb 26 11:45:06 2014 Thibaut Lopez
##

CC=		gcc

RM=		rm -f

CFLAGS=		-Wall -ggdb3 -g3

NAME=		asm

SRCS=		main.c \
		op.c \
		parsing.c \
		basic.c \
		xfunction.c \
		get_next_line.c \
		recup.c

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

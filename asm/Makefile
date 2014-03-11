##
## Makefile for Corewar in /home/odet_a/work/Corewar/asm
##
## Made by
## Login   <odet_a@epitech.net>
##
## Started on  Thu Feb 27 18:18:06 2014
## Last update Tue Mar 11 17:58:20 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I../

NAME=		asm

SRCS=		main.c \
		op.c \
		parsing.c \
		get_next_line.c \
		recup.c \
		fill_header.c \
		init.c \
		recup_comment.c \
		error.c \
		create_cor.c \
		check_label.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L../ -lmy

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re

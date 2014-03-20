##
## Makefile for Corewar in /home/odet_a/work/Corewar/asm
##
## Made by
## Login   <odet_a@epitech.net>
##
## Started on  Thu Feb 27 18:18:06 2014
## Last update Thu Mar 20 19:15:30 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I../ -I../my -I.

NAME=		asm

SRCS=		main.c \
		error.c \
		create_cor.c \
		Parsing/parsing.c \
		Parsing/check_cmd.c \
		Get_Next_Line/get_next_line.c \
		Header/init.c \
		Header/fill_header.c \
		Header/recup_comment.c \
		Header/recup.c \
		../op.c \
		Parsing/check_label.c


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

##
## Makefile for corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Mar 24 12:19:30 2014 romaric
## Last update Sat Apr  5 17:12:38 2014 Thibaut Lopez
##

CC=		gcc

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I../.. -I../../my -I.

NAME=		dasm

SRCS=		create_dot_s.c \
		main.c \
		Function/get_encode.c \
		Function/ld_fun.c \
		Function/no_encode.c \
		Function/operation.c \
		Function/other_fun.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L../../ -lmy

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re

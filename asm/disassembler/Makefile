##
## Makefile for corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Mar 24 12:19:30 2014 romaric
## Last update Sun Apr 13 22:51:27 2014 romaric
##

CC=		gcc

RM=		rm -f

CFLAGS=		-Wall -Wextra -Werror -I../.. -I../../my -I.

NAME=		dasm

SRCS=		create_dot_s.c \
		main.c \
		function/get_encode.c \
		function/ld_fun.c \
		function/no_encode.c \
		function/operation.c \
		function/other_fun.c

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

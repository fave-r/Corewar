##
## Makefile for Corewar in /home/odet_a/work/Corewar/asm
##
## Made by
## Login   <odet_a@epitech.net>
##
## Started on  Thu Feb 27 18:18:06 2014
## Last update Fri Mar 21 14:47:56 2014 alex-odet
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -g -I../ -I../my -I.

NAME=		asm

SRCS=		main.c \
		error.c \
		create_cor.c \
		my_str_to_wordtab.c \
		../op.c \
		Parsing/parsing.c \
		Parsing/check_cmd.c \
		Parsing/check_label.c \
		Get_Next_Line/get_next_line.c \
		Header/init.c \
		Header/fill_header.c \
		Header/recup_comment.c \
		Header/recup.c \
		List/my_put_in_list.c \
		List/my_show_list.c \

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

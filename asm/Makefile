##
## Makefile for corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Mar 24 12:19:30 2014 romaric
## Last update Sun Apr  6 19:06:45 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I../ -I../my -I.

NAME=		asm

SRCS=		main.c \
		create_cor.c \
		my_str_to_wordtab.c \
		count_dot.c \
		cmd.c \
		../op.c \
		parsing/parsing.c \
		parsing/check_cmd.c \
		parsing/check_label.c \
		parsing/check_arg.c \
		parsing/check_live.c \
		parsing/my_writer.c \
		header/init.c \
		header/fill_header.c \
		header/recup_comment.c \
		header/recup.c \
		list/my_put_in_list.c \
		list/my_put_in_cmd_list.c \
		list/my_show_list.c \
		list/my_list_size.c \
		error/error.c \
		error/bad_value.c \
		get_Next_Line/get_next_line.c \
		get_Next_Line/get_next_line_next.c \
		parsing/check_ld.c \
		parsing/error_ld.c \
		parsing/check_st.c

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

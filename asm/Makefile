##
## Makefile for corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Mar 24 12:19:30 2014 romaric
## Last update Fri Apr 11 22:54:11 2014 alex-odet
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I../ -I../my -I.

NAME=		asm

SRCS=		main.c \
		create_cor.c \
		count_dot.c \
		cmd.c \
		../op.c \
		parsing/parsing.c \
		parsing/check_cmd.c \
		parsing/check_label.c \
		parsing/check_arg.c \
		parsing/check_live.c \
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
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_next.c \
		parsing/check_ld.c \
		parsing/encodage.c \
		parsing/error_ld.c \
		parsing/check_st.c \
		parsing/check_add.c \
		parsing/check_and.c \
		parsing/check_ldi.c \
		parsing/check_sti.c \
		parsing/copi_labeldei.c \
		parsing/check_cmdini.c \
		writer/no_encode.c \
		parsing/check_aff.c \
		writer/write_st.c \
		writer/copy_reg_value.c \
		writer/size_to_malloc.c \
		writer/write_ld.c \
		writer/write_lld.c \
		writer/write_lldi.c \
		writer/write_sti.c \
		writer/write_add.c \
		writer/write_aff.c \
		writer/write_and.c \
		writer/write_ldi.c \
		writer/write_or.c \
		writer/write_sub.c

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

##
## Makefile for Corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue Feb 25 18:54:15 2014 romaric
## Last update Tue Feb 25 18:54:19 2014 romaric
##

NAME=	asm

CC=	gcc -W -Wall

SRC=	main.c \
	op.c \
	parsing.c \
	basic.c \
	xfunction.c \
	get_next_line.c

RM=	rm -f

T=	*~

all:
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(T)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

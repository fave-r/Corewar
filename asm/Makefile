##
## Makefile for Makefile in /home/odet_a/Corewar
## 
## Made by 
## Login   <odet_a@epitech.net>
## 
## Started on  Mon Feb 17 04:28:28 2014 
## Last update Mon Feb 24 14:57:47 2014 
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

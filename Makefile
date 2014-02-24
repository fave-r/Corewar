##
## Makefile for Makefile in /home/odet_a/Corewar
## 
## Made by 
## Login   <odet_a@epitech.net>
## 
## Started on  Mon Feb 17 04:28:28 2014 
## Last update Mon Feb 17 18:56:58 2014 
##

NAME=	asm

CC=	gcc -W -Wall

SRC=	main.c \
	op.c \
	parsing/parsing.c \
	parsing/lib/basic.c \
	parsing/lib/xfunction.c \
	parsing/get_next_line/get_next_line.c

RM=	rm -f

T=	*~

all:
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(T)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

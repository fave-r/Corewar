##
## Makefile for Makefile in /home/alex-odet/work/Test_SDL
##
## Made by Alexandre Odet
## Login   <alex-odet@epitech.net>
##
## Started on  Sat Mar  1 14:41:33 2014 Alexandre Odet
## Last update Tue Mar 18 19:54:36 2014 Thibaut Lopez
##

NAME=	SDL_TEST

CC=	gcc -W -Wall -Werror -g3

SRC=	main.c

T=	*~

RM=	rm -f

all:
	$(CC) -o $(NAME) $(SRC) -lSDL -lGL -lGLU

clean:
	$(RM) $(T)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

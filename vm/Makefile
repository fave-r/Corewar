##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Tue Mar 18 19:54:34 2014 Thibaut Lopez
##

VM_S=		champ_fun.c \
		get_encode.c \
		ld_fun.c \
		list_fun.c \
		no_encode.c \
		main.c \
		operation.c \
		other_fun.c \
		run_corewar.c \
		Graphic/main.c

VM_N=		corewar

VM_O=		$(VM_S:.c=.o)

CC=		gcc -g3 -W -Wall -Werror -I ../my/ -I ../ -I .

all:		$(VM_N)

$(VM_N):	$(VM_O)
		$(CC) -o $(VM_N) $(VM_O) -L.. -lmy  -lSDL -lGL -lGLU

clean:
		rm -f $(VM_O)

fclean:		clean
		rm -f $(VM_N)

re:		fclean all

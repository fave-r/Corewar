##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
<<<<<<< HEAD
## Last update Mon Mar 17 20:04:47 2014 thibaud
## Last update Mon Mar 17 16:52:01 2014 Thibaut Lopez
=======
## Last update Mon Mar 17 20:43:23 2014 Thibaut Lopez
>>>>>>> fccb0f17e4753f6766b38dc63e88d2d9698f6899
##

VM_S=		champ_fun.c \
		get_encode.c \
		ld_fun.c \
		list_fun.c \
		no_encode.c \
		main.c \
		operation.c \
		other_fun.c \
		run_corewar.c

VM_N=		corewar

VM_O=		$(VM_S:.c=.o)

CC=		gcc -g3 -W -Wall -Werror -I ../my/ -I ../

all:		$(VM_N)

$(VM_N):	$(VM_O)
		$(CC) -o $(VM_N) $(VM_O) -L.. -lmy

clean:
		rm -f $(VM_O)

fclean:		clean
		rm -f $(VM_N)

re:		fclean all

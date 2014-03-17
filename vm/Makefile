##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
<<<<<<< HEAD
## Last update Mon Mar 17 15:38:41 2014 thibaud
=======
## Last update Mon Mar 17 16:52:01 2014 Thibaut Lopez
>>>>>>> dec3113d2006626c8872b7af3eca2521b7d2e9d5
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

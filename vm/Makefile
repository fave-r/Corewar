##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Wed Mar 12 17:46:04 2014 thibaud
##

VM_S=		champ_fun.c \
		list_fun.c \
		run_corewar \
		main.c

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
